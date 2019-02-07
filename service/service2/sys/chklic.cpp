#include <exodus/library.h>
libraryinit()

#include <cid.h>
#include <secid.h>
#include <sendmail.h>
#include <sysmsg.h>

#include <gen.h>
#include <win.h>

var mode;
var lictext;
var subject;
var body;
var uptodate;
var modulename;
var xx;
var licn;//num
var datedict;
var chkmodulename;
var tt;
var docdate;
var dateorperiod;//num
var did;
var maxexpirydate;//num
var errormsg;

function main(in mode0, out msg) {
	//c sys in,out

	//global mode,modulename,did,uptodate,licn,tt,msg

	//users can always create documents for periods they have lic for
	//IF they hold a lic that has not expired (with some grace days allowed)
	//they can also create documents for other periods

	mode = mode0;

		/* REQUESTING AND ENTERING A VERIFICATION CODE with 7 days grace;
		ADDLIC MEDIA,FINANCE 1/10/2009 31/12/2009 7;
		*/

		/* or entering a verification code 999999 (get other 2 numbers from request);
		ADDLIC MEDIA,FINANCE 1/10/2009 31/12/2009 7 542684 1D63A3AC 999999;
		*/

	//CHKLIC by itself lists the licences installed if any

	//CHKLIC TEST tests an ancient document date

	//DELLIC by itself requests a verification code
	//to remove licencing restrictions (and all licences)

	//DELLIC 999999 (where 999999 is the verification code)
	//removes licencing restrictions (and all licences)

	var maxdaysgrace = 30;
	var maxlicencedays = 366;
	var secidcode = 1090909;
	var allowneosys = 0;

	var lickey = "SYSLICX";

	//LICX in definitions
	//all parallel mv
	//1 uptodate (must be sorted in ascending order)
	//2 fromdate
	//3 modulenames (or * for all)
	//4 datasetid
	//5 daysgrace
	//6 licencetext
	//7 verificationcode

	//mode can be ADD - uses @SENTENCE for parameters
	//otherwise lic is checked using datafile and {YEAR_PERIOD}

	var licxpresent = 1;
	var licx;
	if (not(licx.read(DEFINITIONS, lickey))) {
		licxpresent = 0;
		licx = "";
	}

	var datasetid;
	if (not(datasetid.read(DEFINITIONS, "GLOBALDATASETID"))) {
		msg = "GLOBALDATASETID is missing from DEFINITIONS";
		return 0;
	}
	datasetid = datasetid.a(1);

	if (SENTENCE.field(" ", 1) == "CHKLIC") {
		mode = SENTENCE.field(" ", 2);
	}

	if (mode == "") {

		var cmd = "LIST DEFINITIONS " ^ (DQ ^ (lickey ^ DQ)) ^ " LIC_FIELDS";
		cmd ^= " HEADING " ^ (DQ ^ ("NEOSYS LIC\':\'ENCES as at \'T\'" ^ DQ));
		perform(cmd);
		var().stop();
	}

	if (mode == "TEST") {
		perform("CHKLIC2");
		var().stop();
	}

	if (mode == "DELETE") {

		if (not licxpresent) {
			call mssg("NO LICENCES ARE INSTALLED - CANNOT DELETE");
			var().stop();
		}

		var sentencex = SENTENCE.field("(", 1);
		var options = SENTENCE.field("(", 2);
		var computerid = cid();
		lictext = "DELLIC " ^ computerid ^ " " ^ datasetid;

		var verification = sentencex.field(" ", 2);

		//if incomplete command then prompt for verificationcode
		if (verification == "") {
			call note("PLEASE GIVE THE FOLLOWING TEXT TO YOUR NEOSYS SUPPORT STAFF" ^ FM ^ FM ^ (DQ ^ (lictext ^ DQ)) ^ FM ^ FM ^ "What is the verification code?", "R", verification, "");
			if (not verification) {
				msg = "Verification code not entered";
				return 0;
			}
		}

	//example
	//DELLIC 915036

		var reqverification = secid(lictext, secidcode);
		if (verification ne reqverification) {
			call ossleep(1000*3);
			msg = DQ ^ (verification ^ DQ) ^ " is not the correct verification code";
			return 0;
		}

		if (licxpresent) {
			licx.write(DEFINITIONS, lickey ^ ".PRIOR");
		}

		DEFINITIONS.deleterecord(lickey);
		
		msg = "";

		subject = "NEOSYS: Licencing restrictions removed " ^ SYSTEM.a(17) ^ " - " ^ SYSTEM.a(23);
		body = lictext;
		body.r(-1, "Verification: " ^ verification);
		gosub emailadmin( msg);

		return 0;

	} else if (mode == "ADD") {

		var sentencex = SENTENCE.field("(", 1);
		var options = SENTENCE.field("(", 2);

		var modulenames = sentencex.field(" ", 2);
		var fromdate = sentencex.field(" ", 3);
		uptodate = sentencex.field(" ", 4);
		var daysgrace = sentencex.field(" ", 5);

		var computerid = sentencex.field(" ", 6);
		var cmddatasetid = sentencex.field(" ", 7);
		var verification = sentencex.field(" ", 8);

		if (cmddatasetid and cmddatasetid ne datasetid) {
			msg = sentencex ^ "||" ^ (DQ ^ (cmddatasetid ^ DQ)) ^ " is not the id of the current database (" ^ datasetid ^ ")";
			return 0;
		}

		if ((((modulenames == "") or (fromdate == "")) or (uptodate == "")) or (daysgrace == "")) {
			msg = "";
			gosub syntax( msg);
			return 0;
		}

		var allmodulenames = "MEDIA";
		allmodulenames.r(1, -1, "JOBS");
		allmodulenames.r(1, -1, "FINANCE");
		allmodulenames.r(1, -1, "TIMESHEETS");
		allmodulenames.r(1, -1, "*");

		//check module names
		for (var modulen = 1; modulen <= 9999; ++modulen) {
			modulename = modulenames.field(",", modulen);
		///BREAK;
		if (not modulename) break;;
			if (not(allmodulenames.locateusing(modulename, VM, xx))) {
				msg = "modulename must be one of the following";
				msg.r(-1, allmodulenames);
				return 0;
			}
		};//modulen;

		//check fromdate
		var ifromdate = fromdate.iconv("[DATE,4*]");
		if (not(ifromdate.match("5N"))) {
			msg = DQ ^ (fromdate ^ DQ) ^ " cannot be recognised as a date";
			gosub syntax( msg);
			return 0;
		}

		//check upto date
		var iuptodate = uptodate.iconv("[DATE,4*]");
		if (not(iuptodate.match("5N"))) {
			msg = DQ ^ (uptodate ^ DQ) ^ " cannot be recognised as a date";
			gosub syntax( msg);
			return 0;
		}

		//check fromdate<uptodate
		if (ifromdate >= iuptodate) {
			msg = "fromdate must be before uptodate";
			gosub syntax( msg);
			return 0;
		}

		//check daysgrace numeric
		if (not(daysgrace.match("1N0N"))) {
			msg = DQ ^ (daysgrace ^ DQ) ^ " days grace must be numeric";
			gosub syntax( msg);
			return 0;
		}

		//limit days grace
		if (daysgrace > maxdaysgrace) {
			msg = "the number of days grace is limited to " ^ maxdaysgrace;
			return 0;
		}

		//limit the size of future licences, but not historical
		var nfuturedays = iuptodate - var().date();
		if (ifromdate > var().date()) {
			nfuturedays -= ifromdate - var().date();
		}
		if (nfuturedays > maxlicencedays) {
			msg = "the maximum licence period in the future is " ^ maxlicencedays ^ " days";
			return 0;
		}

		//if incomplete command then prompt for verificationcode
		if (((computerid == "") or (cmddatasetid == "")) or (verification == "")) {
			if (computerid == "") {
				computerid = cid();
			}
			if (cmddatasetid == "") {
				cmddatasetid = datasetid;
			}
			lictext = modulenames;
			lictext ^= " " ^ fromdate;
			lictext ^= " " ^ uptodate;
			lictext ^= " " ^ daysgrace;
			lictext ^= " " ^ computerid;
			lictext ^= " " ^ cmddatasetid;
			call note("PLEASE GIVE THE FOLLOWING TEXT TO YOUR NEOSYS SUPPORT STAFF" ^ FM ^ FM ^ (DQ ^ (lictext ^ DQ)) ^ FM ^ FM ^ "What is the verification code?", "R", verification, "");
			if (not verification) {
				msg = "Verification code not entered";
				return 0;
			}
		}else{
			lictext = sentencex.field(" ", 2, 6);
		}

	//example
	//ADDLIC MEDIA,FINANCE 1/10/2009 31/12/2009 7 542684 1D63A3AC 915036

		var reqverification = secid(lictext, secidcode);
		if (verification ne reqverification) {
			call ossleep(1000*3);
			msg = DQ ^ (verification ^ DQ) ^ " is not the correct verification code";
			return 0;
		}

		if (options.index("O")) {
			licx = "";
		}

		//skip for now since can be duplicated by chance (secid/hash function)
		//following licences produce the same authorisation requirement/code
		// 1/4/2015 30/6/2015 7
		// 1/4/2016 30/6/2016 7
		//locate reqverification in licx<7> setting licn then
		// msg=quote(lictext):' already added'
		// return
		// end

		for (var modulen = 1; modulen <= 9999; ++modulen) {

			modulename = modulenames.field(",", modulen);
		///BREAK;
		if (not modulename) break;;

			//ideally in numerical order by licence "upto" date
			//checking code does not need it though
			if (not(licx.a(1).locateby(iuptodate, "AR", licn))) {
				{}
			}

			licx.inserter(1, licn, iuptodate);
			licx.inserter(2, licn, ifromdate);
			licx.inserter(3, licn, modulename);
			licx.inserter(4, licn, cmddatasetid);
			licx.inserter(5, licn, daysgrace);
			licx.inserter(6, licn, lictext);
			licx.inserter(7, licn, reqverification);

			licx.write(DEFINITIONS, lickey);

		};//modulen;

		subject = "NEOSYS: Licence Added " ^ SYSTEM.a(17) ^ " - " ^ SYSTEM.a(23);
		body = "Licence:     : " ^ SENTENCE.field(" ", 2, 999);
		body.r(-1, "Verification : " ^ verification);
		var nlics = licx.a(1).count(VM) + 1;
		body ^= FM ^ FM;
		body ^= "From          Upto          Module          Days Grace";
		body.r(-1, "----------    ----------    --------------- ----------");
		for (licn = 1; licn <= nlics; ++licn) {
			body ^= FM;
			body ^= licx.a(2, licn).oconv("[DATE,4]") ^ "   ";
			body ^= " " ^ licx.a(1, licn).oconv("[DATE,4]") ^ "   ";
			body ^= " " ^ licx.a(3, licn).oconv("L#15") ^ " ";
			body ^= "    " ^ licx.a(5, licn);
		};//licn;
		body ^= FM;
		body.swapper("/ ", "/0");

		gosub emailadmin( msg);
		return 0;

	}
//L1722:
	/////////////////////////////////////////
	//from here on we are checking if licenced
	/////////////////////////////////////////

	//ok if not creating a new record
	if (win.orec ne "") {
		goto ok;
	}

	//ok if no lic info (for now)
	if (not licxpresent) {
		goto ok;
	}

	//ok if the neosys user
	if (allowneosys and (USERNAME == "NEOSYS")) {
		goto ok;
	}

	//no lic check on neosys development machines
	if (allowneosys and var("NEOSYS.ID").osfile()) {
		goto ok;
	}

	msg = "NEOSYS Lic" "ence: ";

	if (win.datafile == "SCHEDULES") {
		datedict = "STOPDATE";
		chkmodulename = "MEDIA";

	} else if (win.datafile == "PLANS") {
		datedict = "PERIOD_TO";
		chkmodulename = "MEDIA";

	} else if (win.datafile == "JOBS") {
		datedict = "YEAR_PERIOD";
		chkmodulename = "JOBS";

	} else if ((win.datafile == "PRODUCTION_INVOICES") or (win.datafile == "PRODUCTION_ORDERS")) {
		datedict = "DATE";
		chkmodulename = "JOBS";

	} else if (win.datafile == "BATCHES") {
		datedict = "YEAR_PERIOD";
		chkmodulename = "FINANCE";

	} else if (win.datafile == "TIMESHEETS") {
		datedict = "DATE";
		chkmodulename = "TIMESHEETS";

	} else {
		msg = DQ ^ (win.datafile ^ DQ) ^ " datafile is invalid in chklic";
		return 0;
	}
//L2005:
	//determine document date or use last date of documents period
	tt = calculate(datedict);
	if (tt.match("5N")) {
		docdate = tt;
		dateorperiod = 1;
	} else if (tt.index(".")) {
		docdate = (tt ^ ".31").iconv("DJ");
		if (not docdate) {
			docdate = (tt ^ ".30").iconv("DJ");
		}
		if (not docdate) {
			docdate = (tt ^ ".28").iconv("DJ");
		}
		dateorperiod = 2;
	} else if (tt.index("/")) {
		docdate = ("31/" ^ tt).iconv("D/E");
		if (not docdate) {
			docdate = ("30/" ^ tt).iconv("D/E");
		}
		if (not docdate) {
			docdate = ("28/" ^ tt).iconv("D/E");
		}
		dateorperiod = 2;
	} else {
		msg = DQ ^ (tt ^ DQ) ^ " unrecognisable period or date in " ^ win.datafile ^ " " ^ ID;
		return 0;
	}
//L2224:
	//ok if document 1/period/year is in a specifically authorised lic period
	//skip expired licences
	if (not(licx.a(1).locateby(docdate, "AR", licn))) {
		{}
	}
	//check remaining licences which havent expired
	for (licn = licn; licn <= 9999; ++licn) {
		uptodate = licx.a(1, licn);
	///BREAK;
	if (not uptodate) break;;
		did = licx.a(4, licn);
		if ((did == datasetid) and (docdate >= licx.a(2, licn))) {
			modulename = licx.a(3, licn);
			if (modulename == "*") {
ok:
				msg = "";
				return 0;
			}
			if (modulename == chkmodulename) {
				goto ok;
			}
		}
	};//licn;

	//ok if current date is not after last expiry date plus grace days
	var nlics = licx.a(1).count(VM) + (licx ne "");
	//find last expiry date for current module
	var maxfinalexpirydate = "";
	var mincommencedate = "";
	for (licn = 1; licn <= nlics; ++licn) {
		modulename = licx.a(3, licn);
		did = licx.a(4, licn);
		if ((did == datasetid) and (((modulename == "*") or (modulename == chkmodulename)))) {

			var expirydate = licx.a(1, licn);
			var daysgrace = licx.a(5, licn);
			var finalexpirydate = expirydate + daysgrace;

			if (finalexpirydate > maxfinalexpirydate) {
				maxexpirydate = expirydate;
				maxfinalexpirydate = finalexpirydate;
			}

			var commencedate = licx.a(2, licn);
			if ((commencedate < mincommencedate) or not mincommencedate) {
				mincommencedate = commencedate;
			}

		}
	};//licn;

	if (not maxfinalexpirydate) {
		//cannot find any lic (either * or specific)
		msg = "There is no licence to use the NEOSYS " ^ chkmodulename ^ " module";
		return 0;
	}

	if ((var().date() <= maxfinalexpirydate) and (var().date() >= mincommencedate)) {
		msg = "";
		return 0;
	}

	if (dateorperiod == 1) {
		tt = "date";
	}else{
		tt = "period closing";
	}
	msg = "The document " ^ tt ^ " " ^ docdate.oconv("[DATE,4*]") ^ " is not within";
	msg.r(-1, "the NEOSYS licence period ");
	msg ^= mincommencedate.oconv("[DATE,4*]") ^ " - ";
	msg ^= maxexpirydate.oconv("[DATE,4*]");
	tt = var().date() - maxexpirydate;
	msg.r(-1, " and it is now " ^ var().date().oconv("[DATE,4*]") ^ " - " ^ tt ^ " days after the licence expiry date");

	return 0;

}

subroutine emailadmin(io msg) {
	//emailadmin(io msg)
	call sendmail("admin@neosys.com", "", subject, body ^ "", "", "", errormsg);
	call sysmsg(body);

	if (mode == "DELETE") {
		msg = "Licencing restrictions removed; and all licences";
	}else{
		msg = "Licence added OK.";
	}
	if (errormsg) {
		msg.r(-1, " but could NOT email admin@neosys.com" ^ FM ^ FM ^ errormsg);
		call mssg(msg);
	}else{
		call note(msg ^ FM ^ FM ^ "admin@neosys.com has been emailed" ^ FM);
	}
	msg = "";

	return;

}

subroutine syntax(io msg) {
	//syntax(io msg)
	msg.r(-1, "Syntax is:" ^ FM ^ FM ^ "ADDLIC modulename fromdate uptodate daygrace");
	msg.r(-1, FM ^ "or " ^ FM ^ FM ^ "ADDLIC modulename fromdate uptodate daygrace compid databaseid verification");
	msg.r(-1, FM);
	return;

}


libraryexit()