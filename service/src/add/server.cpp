#include <exodus/program.h>
programinit()

#include <win.h>
#include <gen.h>
#include <fin.h>
#include <agy.h>
#include <booking.h>
#include <booking2.h>

function main() {

	//NB numbers and names MUST match those in the matching common .h files
        mv.labelledcommon[1]=new win_common;
        mv.labelledcommon[2]=new gen_common;
        mv.labelledcommon[3]=new fin_common;
        mv.labelledcommon[4]=new agy_common;
        mv.labelledcommon[5]=new booking_common;
        mv.labelledcommon[6]=new booking2_common;

	//cat ~/arev/dic/*.SQL | psql -h 127.0.0.1 -U exodus exodus

	createfile("VOC");
	createfile("DEFINITIONS");
	createfile("PROCESSES");
	createfile("REQUESTLOG");
	createfile("SYS_MESSAGES");

        //batch mode
        SYSTEM.r(33,1,"1");

        //user
        SYSTEM.r(33,2,"NEOSYS");
        SYSTEM.r(33,3,"NEOSYS");

        //module
        APPLICATION="ADAGENCY";

	//user
	USERNAME="exodus";

	//database
	var databasecode="exodus";
	SYSTEM.r(17,databasecode);

	//create database dir
	var datadir="../data/";
	var databasedir=datadir ^ databasecode;
	if (osmkdir(databasedir)) {
		osshell("chmod g+rws " ^ databasedir);
		osshell("setfacl -d -m g::rw " ^ databasedir);
	}

	//ensure MARKETS file exists and has at least an ALL markets record
	if (not open("MARKETS")) {
		createfile("MARKETS");
	}
	select("MARKETS");
	if (var().hasnext())
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

	//neosys pass
	var rec="";
	write(rec.r(7,invert("ALSOWINE")),"DEFINITIONS","NEOSYS");

	//kick off with initgeneral
        var cmd=SENTENCE.field(" ",2,9999);
        if (not cmd)
                cmd=SENTENCE="initgeneral LOGIN";
        perform(cmd);

        return 0;
}

programexit()

