#include <exodus/program.h>
programinit()

#include <win_common.h>
#include <gen_common.h>
#include <agy_common.h>
#include <initcompany.h>

var xx;

function main() {

	//NB numbers and names MUST match those in the matching common .h files
	mv.labelledcommon[win_common_no]=new win_common;
	mv.labelledcommon[gen_common_no]=new gen_common;
	mv.labelledcommon[agy_common_no]=new agy_common;

	/*cat ~/arev/dic/ *.SQL | psql -h 127.0.0.1 -U exodus exodus*/

	//gen.addresses="addresses";
	//gen.timesheets="timesheets";
	//gen.companies="companies";
	//gen.currencies="currencies";
	//gen.documents="documents";
	//gen.units="units";

	createfile("VOC");
	createfile("DEFINITIONS");
	createfile("PROCESSES");
	createfile("REQUESTLOG");
	createfile("SYS_MESSAGES");
	createfile("COMPANIES");
	createfile("MARKETS");
	createfile("USERS");

	//module
	APPLICATION="EXODUS";

	//user
	USERNAME="exodus";

	//database
	var databasecode="exodus";
	SYSTEM.r(17,databasecode);

	//process no
	SYSTEM.r(24,PROCESSNO);

	//f5 key
	PRIORITYINT.r(2,"x");

	//create database dir
	var datadir="../data/";
	if (not osdir(datadir))
		abort(datadir.quote() ^ " data directory does not exist");
	var databasedir=datadir ^ databasecode;
	if (osmkdir(databasedir)) {
		osshell("chmod g+rws " ^ databasedir);
		osshell("setfacl -d -m g::rw " ^ databasedir);
	}

	/*
	//ensure MARKETS file exists and has at least an ALL markets record
	if (not open("MARKETS")) {
		createfile("MARKETS");
	}
	select("MARKETS");
	if (hasnext())
		clearselect();
	else
		write("All Markets","MARKETS","ALL");

	var agp="";
	if (not read(agp,"DEFINITIONS","AGENCY.PARAMS")) {
		agp=invert("DEVELOPMENT DATABASE");
		agp.r(4,1);//short dates
		//agp.r(5,1);//split extras
		agp.r(7,1);//wording on schedules
		write(agp,"DEFINITIONS","AGENCY.PARAMS");
	}
	*/

	call initcompany();

	//neosys pass
	var rec="";
	write(rec.r(7,invert("ALSOWINE")),"DEFINITIONS","NEOSYS");

	//kick off with initgeneral or some custom command
	var cmd=SENTENCE.field(" ",2,9999);
	if (cmd)
		perform(cmd);
	else {
		//batch mode
		SYSTEM.r(33,1,"1");
		//user
		SYSTEM.r(33,2,"NEOSYS");
		SYSTEM.r(33,3,"NEOSYS");

		perform("listen");
	}

	return 0;
}

programexit()

