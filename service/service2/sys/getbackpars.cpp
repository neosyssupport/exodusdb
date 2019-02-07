#include <exodus/library.h>
libraryinit()


#include <gen.h>

var process;
var tt;//num
var dbn;
var xx;

function main(out bakpars, in process0=var()) {
	//c sys out,=var()

	//optonally get the backpars for a specific process if given
	if (process.unassigned()) {
		process = SYSTEM;
	}else{
		process = process0;
	}

	//by test data means any non-live data that doesnt require backup

	//backup params
	//1=date last attempted
	//!2= not used - was workstation for backup (blank defaults to server)
	//3=min time of day for backup to start (defaults to 01:00)
	//4=max time of day for backup to start (defaults to 01:05)
	//5=days to do backup 1234567 1=sun NIGHT!!! EG 2AM
	//2/3/4/5 could be multivalued in parallel (to be programmed)
	//6=tech support email addresse(s) separated by ';'
	//7=backup disk letter
	//8=mv list of datasets NOT to backup (ctrl+E to edit) (Not used if any backups defined in Configuration File)
	//9=1 disable both backup and shutdown
	//10=email addresses to send backup.zip to OR replacement for 6 if 6 missing
	//backups@neosys.com is excluded in NET from backup.zip recipients
	//11=1=suppress backup but do shutdown (testdata) (Doesnt suppress if any backups defined in Configuration File)
	//12=backup disk for uploads (images) folder if different from 7. Put 0 to suppress backup.
	//13='' is default (weekly rotation) 1=wrong media doesnt fail the backup
	//max 30 since copied into system.cfg for editing
	if (not(bakpars.read(DEFINITIONS, "BACKUP"))) {
		bakpars = "";
	}
	if (tt.osread("BACKUP.CFG")) {
		for (var ii = 1; ii <= 99; ++ii) {
			if (tt.a(ii).length()) {
				bakpars.r(ii, tt.a(ii));
			}
		};//ii;
	}
	if (tt.osread("..\\..\\BACKUP.CFG")) {
		for (var ii = 1; ii <= 99; ++ii) {
			if (tt.a(ii).length()) {
				bakpars.r(ii, tt.a(ii));
			}
		};//ii;
	}

	//if bakpars<3>='' then bakpars<3>='2:00'
	//if bakpars<4>='' then bakpars<4>='2:05'
	if (bakpars.a(3) == "") {
		bakpars.r(3, "1:00");
	}
	if (bakpars.a(4) == "") {
		bakpars.r(4, "1:05");
	}
	if (not(bakpars.a(3).isnum())) {
		bakpars.r(3, bakpars.a(3).iconv("MT"));
	}
	if (not(bakpars.a(4).isnum())) {
		bakpars.r(4, bakpars.a(4).iconv("MT"));
	}
	if (bakpars.a(5) == "") {
		bakpars.r(5, "1234567");
	}

	//fix bug in data entry that allows : and :: to be entered
	if (bakpars.a(7)[1] == ":") {
		bakpars.r(7, "");
	}
	if (bakpars.a(12)[1] == ":") {
		bakpars.r(12, "");
	}

	if (not(bakpars.a(7))) {
		bakpars.r(7, "C:");
	}
	if (bakpars.a(12) == "") {
		bakpars.r(12, bakpars.a(7));
	}

	//backup depending on configuration file
	//if any database listed there
	if (process.a(58)) {

		//databases to be excluded
		bakpars.r(8, "");

		//decide backup required or not by indicating testdata
		if (process.a(58).locateusing(process.a(17), VM, dbn)) {
			tt = process.a(60, dbn);
		}else{
			tt = 0;
		}
		//test/nonlive data
		bakpars.r(11, not tt);

		//otherwise backup depending on BACKUP.CFG etc
	}else{

		//autodetermine if it is "test" data
		if (bakpars.a(11) == "") {
			var testdata = 1;
			if (process.a(17).substr(-4,4) == "TEST") {
			} else if (process.a(23).ucase().index("TRAINING")) {
			} else if (process.a(23).ucase().index("TESTING")) {
			} else {
				//not otherwise specified then exclude database if in list of non-live data
				//none-live could include test data or consolidated copies
				if (not(bakpars.a(8).locateusing(process.a(17), VM, xx))) {
					testdata = 0;
				}
			}
			bakpars.r(11, testdata);
		}

	}

	return 0;

}


libraryexit()