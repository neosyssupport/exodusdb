#include <exodus/program.h>
programinit()

	var last_sync_date;
	var last_sync_time;

function main() {

	var homedir;
	if (not homedir.osgetenv("EXO_HOME"))
		homedir = osgetenv("HOME");

	var datpath = COMMAND.a(2);
	if (not datpath) {
		datpath = homedir ^ "/dat";
	}

	var force = index(OPTIONS, "F");
	var generate_dict_cpp = index(OPTIONS, "G");
	var verbose = index(OPTIONS, "V");

	var txtfmt = "TX";

	// Skip if no definitions file
	var definitions;
	if (not open("DEFINITIONS",definitions)) {
		//abort("Error: sync_dat - No DEFINITIONS file");
		definitions = "";
	}

	// Get the date and time of last sync
	var last_sync;
	var definitions_key = "LAST_SYNC_DATE_TIME*DAT";
	if (not definitions or not read(last_sync,definitions, definitions_key))
		last_sync = "";
	last_sync_date = last_sync.a(1);
	last_sync_time = last_sync.a(2);

	// Skip if nothing new
	var datinfo = osdir(datpath);
	var dirtext = "sync_dat: " ^ datpath ^ " " ^ datinfo.a(2).oconv("D-Y") ^ " " ^ datinfo.a(3).oconv("MTS");
	if (not force and not is_newer(datinfo)) {
		if (verbose)
			printl(dirtext, "No change.");
		return 0;
	}
	printl(dirtext,"Scanning ...");

	begintrans();

	// Process each subdir in turn. each one represents a db file.
	var dirnames = oslistd(datpath ^ "/*").sort();
	for (var dirname : dirnames) {

		var dirpath = datpath ^ "/" ^ dirname ^ "/";

//		// Skip dirs which are not newer i.e. have no newer records
//		if (not force) {
//			var dirinfo = osdir(dirpath);
//			if (not is_newer(dirinfo)) {
//				if (verbose)
//					printl("Nothing new in", dirpath, dirinfo.a(2).oconv("D-Y"), dirinfo.a(3).oconv("MTS"));
//				continue;
//			}
//		}

		// Open or create the target db file
		var dbfile;
		var dbfilename = dirname;
		if (not open(dbfilename, dbfile)) {
			createfile(dbfilename);
			if (not open(dbfilename, dbfile)) {
				errputl("Error: sync_dat cannot create " ^ dbfilename);
				continue;
			}
		}

		var add2cpp = generate_dict_cpp and dbfilename.starts("dict.");
		var newcpptext = "#include <exodus/library.h>\n";

		// Process each dat file/record in the subdir
		var osfilenames = oslistf(dirpath ^ "*").sort();
		for (var osfilename : osfilenames) {

			ID = osfilename;

			if (not ID)
				continue;

			if (ID.starts(".") or ID.ends(".swp"))
				continue;

			// Get the dat record
			var filepath = dirpath ^ ID;
			if (not osread(RECORD from filepath)) {
				errputl("Error: sync_dat cannot read " ^ ID ^ " from " ^ filepath);
				continue;
			}

			// unescape to convert from txt to pickos format.
			RECORD = RECORD.iconv(txtfmt);

			// Add it to newcpptext
			if (add2cpp and RECORD.a(1) eq "S") {

				// dict intro
				var line1 = "\nlibraryinit(" ^ ID.lcase() ^ ")";
				newcpptext ^= line1 ^ "\n";
				newcpptext ^= "/" "/" ^ str("-", len(line1) - 3) ^ "\n";

				var dictsrc = RECORD(8);
				dictsrc.converter(VM, "\n");

				// Add dict function intro
				var addfunctionmain = not dictsrc.index("function main()");
				if (addfunctionmain) {
					newcpptext ^= "function main() {\n";

					// Add closing brace before pgsql , if present
					var t = dictsrc.index("\n/*pgsql");
					if (t) {
						dictsrc.splicer(t, 1, "\n}\n");
						addfunctionmain = false;
					}
				}
//TRACE(ID)
//TRACE(dictsrc)
//stop();
				newcpptext ^= dictsrc ^ "\n";

				// Close function main if not already done
				if (addfunctionmain)
					newcpptext ^= "}\n";

				// dict outro
				newcpptext ^= "libraryexit(" ^ ID.lcase() ^ ")\n\n";

			}

			// Skip files/records which are not newer
			if (not force and not is_newer(osfile(filepath))) {
				if (verbose)
					printl("Not newer", dbfilename, ID);
				continue;
			}

			// Moved up so we can generate complete dict_xxxxxxxx.cpp source
			//if (not osread(RECORD from filepath)) {
			//	errputl("Error: sync_dat cannot read " ^ ID ^ " from " ^ filepath);
			//	continue;
			//}
			//gosub unescape_text(RECORD);

			//get any existing record
			var oldrecord;
			if (not read(oldrecord from dbfile, ID)) {
				oldrecord = "";
			}

			if (RECORD eq oldrecord) {
				if (verbose)
					printl("Not changed", dbfilename, ID);
			} else {
				// Write the RECORD
				write(RECORD on dbfile, ID);
				printl("sync_dat:", dbfilename, ID, "WRITTEN");
			}

			// Create pgsql using dict2sql
			// DONT SKIP SINCE PGSQL FUNCTIONS MUST BE IN EVERY DATABASE
			if (dbfilename.starts("dict.") and RECORD.index("/" "*pgsql")) {
				var cmd = "dict2sql " ^ dbfilename ^ " " ^ ID;
				//cmd ^= " {V}";
				if (not osshell(cmd))
					errputl("Error: sync_dat: In dict2sql for " ^ ID ^ " in " ^ dbfilename);
			}


		} // next dat file

		if (add2cpp) {
			var dictcppfilename = "dict_" ^ dirname;

			var incfilename = homedir ^ "/inc/" ^ dbfilename.convert(".", "_") ^ ".h";

			var incfiletext;
			if (not osread(incfiletext from incfilename)) {
				//abort("sync_dat cannot read " ^ incfilename);
				errputl("sync_dat cannot read " ^ incfilename);
				continue;
			}

			dictcppfilename = incfiletext.field(DQ, 2).field(" ", 2);
			var oldcpptext;
			if (not osread(oldcpptext from dictcppfilename))
				oldcpptext = "";

			if (newcpptext ne oldcpptext) {
				//if (not oswrite(newcpptext on dbfilename))
				if (not oswrite(newcpptext on dictcppfilename))
					abort("sync_dat cannot write " ^ dictcppfilename);
				printl("Updated", dictcppfilename);
				if (not osshell("compile " ^ dictcppfilename))
					abort("sync_dat could not compile " ^ dictcppfilename);
			}
		}

	} // next dat dir

	// Record the current sync date and time
	if (definitions)
		write(date() ^ FM ^ time() on definitions, definitions_key);

	committrans();

	return 0;
}

function is_newer(in fsinfo) {

    int fsinfo_date = fsinfo.a(2);

    if (fsinfo_date > last_sync_date)
        return true;

    if (fsinfo_date < last_sync_date)
        return false;

    return fsinfo.a(3) > last_sync_time;

}

programexit()

