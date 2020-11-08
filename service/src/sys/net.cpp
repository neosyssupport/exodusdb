#include <exodus/library.h>
libraryinit()

#include <log.h>
#include <sysmsg.h>
#include <getbackpars.h>
#include <sendmail.h>
#include <upgrade.h>

#include <gen_common.h>

var tt;//num
var bakpars;
var ver;

function main() {
	//c sys

	#include <general_common.h>

	//if @username='NEOSYS' then break on
	//BREAK ON;

	var cmd = "LISTEN " ^ SENTENCE.field(" ", 2, 9999);

	PSEUDO = "";
	USER4 = "";
	PRIORITYINT.r(100, "");
	var dbcode = SYSTEM.a(17);
	if (dbcode == "") {
		dbcode = "DEFAULT";
	}

	if (not(DEFINITIONS.open("DEFINITIONS", ""))) {
		call fsmsg();
		stop();
	}

listen:

	var s33 = SYSTEM.a(33);

	//forces OFF in listen on esc
	if (cmd.field(" ",1) ne "LISTEN") {
		SYSTEM.r(33, 1);
	}

	execute(cmd);

	//unlock all
	var xx = unlockrecord();

	SYSTEM.r(33, "");

	if (USER4.substr(1,7) == "RESTART") {

		if (USER4 == "RESTART $LISTEN") {
			SYSTEM.r(100, 3, "");
			SYSTEM.r(33, s33);
			goto listen;
		}

		stop();
		////

	}

	if ((USER4 == "") or (USER4 == "TERMINATED OK")) {
		stop();
		////
	}

	//stop if cant backup because another process is backing up or hung processes
	if (USER4.index("FILEMAN-SHUTDOWN")) {
		perform("OFF");
		var().logoff();
	}

	//check lists and indexing files are not corrupted and zero them if they are
	//listen selects the locks file every 10 secs and may detect corruption
	s33 = SYSTEM.a(33);
	SYSTEM.r(33, 1);
	//call checkfile"LISTS");
	//call checkfile"!INDEXING");
	//call checkfile"LOCKS");
	SYSTEM.r(33, s33);

	//detect memory corruption?
	var halt = 0;
	if (USER4.index("R18.6")) {
		halt = 1;
		USER4.r(-1, "Corrupt temporary file. Restart Needed.");
		USER4.r(-1, "NEOSYS.NET TERMINATED");
	}
	if (USER4.ucase().index("NOT ENOUGH MEMORY")) {
		halt = 1;
	}
	if (USER4.ucase().index("OUT OF MEMORY")) {
		halt = 1;
	}

	//convert error messages
	var normal = 0;
	if (USER4.index("INDEX.REDUCER")) {
		normal = 1;
		USER4 = "Error: Please select fewer records";
	}

	if (not normal) {

		//determine subject
		var subject = "";
		var attachfilename = "";

		//either BACKUP or BACKUP2 followed by space and drive letter
		if (PSEUDO.substr(1,6) == "BACKUP") {

			subject = "NEOSYS Backup " ^ dbcode;

			//add drive letter(s)
			tt = PSEUDO.field(" ", 2).substr(1,2);
			var tt2 = PSEUDO.field(" ", 3).substr(1,2);
			subject ^= " -> " ^ tt;
			if (tt2 and tt2 ne tt) {
				subject ^= "/" ^ tt2;
			}

			//note new or changed media
			tt = USER4.index("Media: ");
			if (tt) {
				subject ^= " " ^ (USER4.substr(tt + 7,9999)).a(1);
			}

			//add success, WARNING or FAILURE
			tt = "";
			tt2 = USER4.ucase();
			if (not(tt2.index("SUCCESS")) or tt2.index("FAIL")) {
				tt = "FAILURE";
			}else{
				if (tt2.index("WARNING")) {
					tt = "WARNING";
				}
				attachfilename = SYSTEM.a(42);
			}
			//no need for specific success message. most succeed, can find FAIL or WARN
			//if tt='' then tt='Success'
			subject ^= " " ^ tt;

			//add neosys version for info
			//call osread(versionnote,'general\version.dat')
			//versiondate=iconv(field(trim(versionnote),' ',2,3),'D')
			//subject:=' Ver: ':versiondate 'D4/J'

			//log it
			var errormsg = USER4;
			call log(cmd, errormsg ^ "");

		}else{

			//subject='NEOSYS Technical Message :'
			subject = "";
			printl(USER4);
			call sysmsg(USER4);

		}

		if (subject) {

			//get backup parameters
			call getbackpars(bakpars);

			//send email of error
			//readv address from definitions,'BACKUP',6 else address=''
			gen.address = bakpars.a(6);
			if (bakpars.a(10)) {
				if (gen.address) {
					gen.address ^= "/";
				}
				gen.address ^= bakpars.a(10);
			}
			if (gen.address == "") {
				if (not(gen.address.readv(DEFINITIONS, "REPLICATION", 12))) {
					gen.address = "";
				}
			}
			if (gen.address == "") {
				gen.address = "backups@neosys.com";
			}
			if (gen.address) {

				var body = "Server=" ^ SYSTEM.a(44).trim();
				body.r(-1, "Client=" ^ STATION.trim());
				body.r(-1, "User=" ^ USERNAME.trim());
				//osread ver from 'general\version.dat' then
				var verfilename = "general/version.dat";
				verfilename.converter("/", OSSLASH);
				if (ver.osread(verfilename)) {
					body.r(-1, "NEOSYS Ver:" ^ ver.a(1));
				}

				//too slow so ignore it
				//servername=getdrivepath(drive()[1,2])[3,'\']
				//if servername then body:=fm:'ServerName=':servername

				body ^= FM ^ FM ^ USER4;
				body.converter(FM ^ VM ^ SVM ^ TM ^ STM ^ "|", "\r" "\r" "\r" "\r" "\r" "\r");
				body.swapper("\r", "\r\n");

				//sendmail - if it fails, there will be an entry in the log
				var address1 = gen.address.field("/", 1);
				var errormsg = "";
				if (address1) {
					call sendmail(address1, "", subject, body, "", "", errormsg);
				}

				//optionally email backup.zip
				if (((errormsg == "") or (errormsg.substr(1,2) == "OK")) and attachfilename) {
					var address2 = gen.address.field("/", 2);
					//remove neosys from the backup.zip recipients
					if (address2.locateusing(";","backups@neosys.com",xx)) {
						address2.converter(";", VM);
						address2.remover(1, xx);
						address2.converter(VM, ";");
					}
					if (address2) {
						call sendmail(address2, "", subject, body, attachfilename);
					}
				}

			}

		}

		//terminate after automatic backup in order to allow os filesystem backups
		//BACKUP2 means dont copydb/upgrade/quit - just resume
		if (PSEUDO.field(" ", 1) == "BACKUP") {

			//before termination do any copy to testdata etc
			if (SYSTEM.a(58).locate(dbcode,tt)) {
				if (SYSTEM.a(62, tt)) {
					perform("COPYDB " ^ dbcode);
				}
			}

			//also before termination do any upgrade
			//why call not perform?
			call upgrade();

			if (SYSTEM.a(125)) {
				perform("OFF");
				var().logoff();
			}
		}

	}

	//respond to client
	var linkfilename3 = PRIORITYINT.a(100);
	if (linkfilename3) {
		//cannot remove these since they may be codepage letters now
		USER4.swapper("|", "\r\n");
		USER4.swapper(FM, "\r\n");
		USER4.swapper(VM, "\r\n");
		call oswrite("Error: " ^ USER4, linkfilename3);
		//osclose linkfilename3
	}

	//restore the original settings
	//noninteractive avoids any further messages on OFF command
	SYSTEM.r(33, s33);
	if (SYSTEM.a(43)) {
		USERNAME=(SYSTEM.a(43));
	}
	//if system<44> then call sysvar_109_110('SET',system<44>)
	if (SYSTEM.a(44)) {
		STATION=(SYSTEM.a(44));
	}

	if (halt) {
		perform("OFF");
		var().logoff();
	}

	if (cmd.field(" ",1) == "LISTEN") {
		//if NET LISTEN LISTEN LISTEN - then terminate if too many errors
		if (cmd.length() > 100) {
			printl(USER4);
			perform("OFF");
		}
		cmd.swapper(" INTRANET", "");
		chain("NET " ^ cmd);
	}

	return 0;
}

libraryexit()