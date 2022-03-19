#include <exodus/program.h>
programinit()

function main() {

	var force = OPTIONS.index("F");
	var indexnames = COMMAND.field(FM, 2, 999999);

	if (not indexnames)
		abort("Syntax is 'createindex [filename] [filename__]fieldname... {F=Force}'");

	if (indexnames eq "xref") {
		indexnames = var().listindexes();
		var indexnames2 = "";
		for (auto index : indexnames) {
			if (index.ends("_xref")) 
				indexnames2 ^= index ^ FM;
		}
		indexnames = indexnames2.pop();
		indexnames.swapper(VM, "__");
		printl(indexnames);
	}

	var nindexes = dcount(indexnames, FM);

	var result = 0;

	var indexn;
	for (indexn = 1; indexn <= nindexes; ++indexn) {

		var filename = indexnames.a(indexn);
		if (not filename)
			break;
		var fieldname;
		var tt = filename.index("__");
		if (tt) {
			fieldname = filename.substr(tt + 2);
			filename = filename.substr(1, tt - 1);
		} else {
			fieldname = indexnames.a(indexn + 1);
			indexn += 1;
		}

		var indexname = filename ^ "__" ^ fieldname;
		if (force && listindexes(filename, fieldname)) {
			printl("Deleting index", indexname);
			if (not filename.deleteindex(fieldname)) {
				errputl("Cannot delete index", indexname);
				result = 1;
			}
		}
		printl("Creating index", indexname);
		if (not filename.createindex(fieldname)) {
			errputl("Cannot create index", indexname);
			result = 1;
		}
	}

	return result;
}

programexit()
