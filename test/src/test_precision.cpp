#undef NDEBUG //because we are using assert to check actual operations that cannot be skipped in release mode testing
#include <cassert>
#include <limits>
#include <iomanip>
//#include <format>
#include <cmath>

//think of ASCII decimal characters as "external format" i.e. that which humans see and enter
//
//think of double as "internal format" i.e. that which computers can work with
//
//think of converting ASCII decimal -> double as "input conversion" (ICONV) i.e from "external format" to "internal format"
//
//think of converting double -> >ASCII decimal as "output conversion" (OCONV) i.e. from "internal format" to "external format"

//fastfloat supports ICONV
//convert ASCII decimal to double ("ICONV")
#if __has_include (<fast_float/fast_float.h>)
#define HAS_FASTFLOAT
#include <fast_float/fast_float.h>
#endif

//ryu support ICONV and OCONV but we only use its OCONV
//1. convert ASCII decimal to double ("ICONV")
//2. convert double to ASCII decimal ("OCONV")
#if __has_include(<ryu/ryu_parse.h>)
#define HAS_RYU
#define USE_RYU_D2S//if using d2s not d2exp in mv.cpp
#include <ryu/ryu_parse.h>
#endif

#include <exodus/program.h>

using namespace std;

programinit()

	double dd1;
	var dv1;
	var dv2;
	var sv1;
	var sv2;

function main() {

	printl("\n========= test_precision ==========");
	{

		printl("\nASSUMING precision(15) in");
		printl("mv.cpp std::string dblToString(double double1)");

		printl("\nNumber of decimal digits that can be round tripped between ASCII decimal and DOUBLE binary without change\nMaximum reliable precision (decimal digits) is ");
		TRACE(numeric_limits<double>::digits10)
		printl("Actually we get one more digit of precision from the left hand side.");

		//example of max precision pure c++ stream conversion double to ASCII
		std::cout << std::setprecision(15) << 1.234567890123456000000 << std::endl;
		std::cout << std::setprecision(15) << 1.234567890123000000000 << std::endl;
		std::cout << std::setprecision(15) << 999999.999999999 << std::endl;
		std::cout << std::setprecision(15) << 1000000.99999999 << std::endl;
		std::cout << std::setprecision(15) << 1999999.99999999 << std::endl;
		std::cout << std::setprecision(15) << 99999999.9999999 << std::endl;
		std::cout << std::setprecision(15) << 999999999.999999 << std::endl;
		std::cout << std::setprecision(15) << 999999999999999.1 << std::endl;
		printl("The following trigger scientific format");
		std::cout << std::setprecision(15) << 999999999999999.9 << std::endl;
		std::cout << std::setprecision(15) << 0.12345678901234567890 << std::endl;
		std::cout << std::setprecision(15) << 0.00005678901234567890 << std::endl;

		//TRACE(numeric_limits<double>::max_digits10)

		cout << "\nsize of double used by var = " << sizeof(double) << std::endl;
		cout <<" size of long double = " << sizeof(long double) << endl;

		//cout << setprecision(16) << fixed << 1234567890123456.789012345678901234567890 << endl;
		//cout << setprecision(16) << fixed << 999999999999999.9 << endl;

		assert( (var(9.36749)        ^ "x") == "9.36749x");
		assert(((var("9.36749") + 0) ^ "x") == "9.36749x");

		assert((var(1234567890123456789.)  ^ "x") == "1234567890123456800x");
		assert((var(12345678901234567890.) ^ "x") == "12345678901234567000x");

		printl( var("999999999999999.9")    + 0);
		//           999999999999999.875
		assert((var("999999999999999.9")    + 0).toString() == "999999999999999.9");
		printl( var("9999999999999999.9")   + 0);
		assert((var("9999999999999999.9")   + 0).toString() == "10000000000000000");
#if defined(HAS_RYU) and not defined(HAS_FASTFLOAT)
		//ryu conversion of ASCII numbers to doubles REJECTS too precise numbers that cannot be round tripped
		assert( ! var("99999999999999999.9").isnum());
		assert( ! var("0.999999999999999999").isnum());

		assert(   var("9999999999999999.9").isnum());
		assert(   var("0.99999999999999999").isnum());
#else
		printl( var("99999999999999999.9")  + 0);
		assert((var("99999999999999999.9")  + 0).toString() == "100000000000000000");
		printl( var("999999999999999999.9") + 0);
		assert((var("999999999999999999.9") + 0).toString() == "1000000000000000000");
#endif
		TRACE(var(10)/var(3));
		assert(var(10)/var(3) == "3.3333333333333333");
		printl(var(999999999999999.9d)    ^ "x");
		assert((var(999999999999999.9d)    ^ "x") == "999999999999999.9x");
		assert((var(9999999999999999.9d)   ^ "x") == "10000000000000000x");
		assert((var(99999999999999999.9d)  ^ "x") == "100000000000000000x");
		assert((var(999999999999999999.9d) ^ "x") == "1000000000000000000x");

		printl("\ntoo many decimal points get ROUNDED");
		dd1 = 0.00005678901234567890d;
		dv1 = dd1;
		dv2 = "0.00005678901234567890d";
		sv1 = dv1^"x";
		//var sv2 = "0.00005678901235x";
		sv2 = "0.0000567890123456789x";
		gosub out();
		assert(sv1 == sv2);

		printl("\ntoo many digits of precision get truncated");
		dd1 = 1234567890.00005678d;
		dv1 = dd1;
		dv2 = "1234567890.00005678d";
		sv1 = dv1 ^ "x";
#ifndef USE_RYU_D2S
		sv2 = "1234567890.000057x";
#else
		sv2 = "1234567890.0000567x";//ryu
#endif
		gosub out();
		assert(sv1 == sv2);

		printl("\nsmall numbers are ok");
		dd1 = 0.00005678d;
		dv1 = dd1;
		dv2 = "0.00005678d";
		sv1 = dv1^"x";
		sv2 = "0.00005678x";
		gosub out();
		assert(sv1 == sv2);

		printl("\nsmallest decimal number");
		dd1=0.0000000000001d;
		dv1 = dd1;
		dv2="0.0000000000001d";
		sv1 = dv1^"x";
		sv2="0.0000000000001x";
		gosub out();
		assert(sv1 == sv2);

		/*
		printl("\nless than smallest decimal number becomes 0.0");
		dd1=0.000000000000009d;
		dv1 = dd1;
		dv2="0.000000000000009d";
		sv1 = dv1^"x";
		sv2="0x";
		gosub out();
		assert(sv1 == sv2);
		*/

		printl("\ncheck largest number (14x9) works without scientific format");
		dd1= 9999999999999.9d;
		dv1 = dd1;
		dv2="9999999999999.9d";
		sv1=dv1^"x";
		sv2="9999999999999.9x";
		gosub out();
		assert(sv1 == sv2);

		printl("\nVery large numbers are rounded and lose accuracy");
		dd1=999999999999999999.9d;
		dv1 = dd1;
		dv2="999999999999999999.9d";
		sv1=dv1^"x";
		sv2="1000000000000000000x";
		gosub out();
		assert(sv1 == sv2);

		printl("\nVery large numbers are rounded and lose accuracy");
		dd1=12345678901234567890123456789.0d;
		dv1 = dd1;
		dv2="12345678901234567890123456789.0d";
		sv1=dv1^"x";
#ifndef USE_RYU_D2S
		sv2="12345678901234570000000000000x";
#else
		sv2="12345678901234568000000000000x";//ryu
#endif
		gosub out();
		assert(sv1 == sv2);

		printl("\ncheck excessive number DONT get converted to scientific");
		dd1=99999999999999.9d;
		dv1 = dd1;
		dv2="99999999999999.9d";
		sv1=dv1^"x";
#ifndef USE_RYU_D2S
		sv2="99999999999999.91x";
#else
		sv2="99999999999999.9x";//ryu
#endif
		gosub out();
		assert(sv1 == sv2);

		//test2 tests both positive and negative round trip chars to chars

        assert(test2("00000000000000000000.00000000000000000000",                   "0x"));
#ifndef USE_RYU_D2S
		assert(test2("00000000000000000000.00000000000000000001",                   "0.000000000000000000009999999999999999x"));
#else
		assert(test2("00000000000000000000.00000000000000000001",                   "0.00000000000000000001x"));//ryu
#endif
		assert(test2("00000000000000000000.00000000000000000012",                   "0.00000000000000000012x"));
		assert(test2("00000000000000000000.00000000000000000123",                   "0.00000000000000000123x"));
		assert(test2("00000000000000000000.00000000000000001234",                   "0.00000000000000001234x"));
		assert(test2("00000000000000000000.00000000000000012345",                   "0.00000000000000012345x"));
		assert(test2("00000000000000000000.00000000000000123456",                   "0.00000000000000123456x"));
		assert(test2("00000000000000000000.00000000000001234567",                   "0.00000000000001234567x"));
		assert(test2("00000000000000000000.00000000000012345678",                   "0.00000000000012345678x"));
		assert(test2("00000000000000000000.00000000000123456789",                   "0.00000000000123456789x"));
		assert(test2("00000000000000000000.00000000001234567890",                   "0.0000000000123456789x"));
		assert(test2("00000000000000000000.00000000012345678901",                   "0.00000000012345678901x"));
		assert(test2("00000000000000000000.00000000123456789012",                   "0.00000000123456789012x"));
		assert(test2("00000000000000000000.00000001234567890123",                   "0.00000001234567890123x"));
		assert(test2("00000000000000000000.00000012345678901234",                   "0.00000012345678901234x"));
		assert(test2("00000000000000000000.00000123456789012345",                   "0.00000123456789012345x"));
		assert(test2("00000000000000000000.00001234567890123456",                   "0.00001234567890123456x"));

#ifdef USE_RYU_D2S
		assert(test2("00000000000000000000.000000000000000000012345678901234567",   "0.000000000000000000012345678901234567x"));
		assert(test2("00000000000000000000.00000000000000000012345678901234567",    "0.00000000000000000012345678901234568x"));
		assert(test2("00000000000000000000.0000000000000000012345678901234567",     "0.0000000000000000012345678901234566x"));
		assert(test2("00000000000000000000.000000000000000012345678901234567",      "0.000000000000000012345678901234567x"));
		assert(test2("00000000000000000000.00000000000000012345678901234567",       "0.00000000000000012345678901234568x"));
		assert(test2("00000000000000000000.0000000000000012345678901234567",        "0.0000000000000012345678901234568x"));
		assert(test2("00000000000000000000.000000000000012345678901234567",         "0.000000000000012345678901234567x"));
		assert(test2("00000000000000000000.00000000000012345678901234567",          "0.00000000000012345678901234566x"));
		assert(test2("00000000000000000000.0000000000012345678901234567",           "0.0000000000012345678901234567x"));
		assert(test2("00000000000000000000.000000000012345678901234567",            "0.000000000012345678901234567x"));
		assert(test2("00000000000000000000.00000000012345678901234567",             "0.00000000012345678901234568x"));
		assert(test2("00000000000000000000.0000000012345678901234567",              "0.0000000012345678901234566x"));
		assert(test2("00000000000000000000.000000012345678901234567",               "0.000000012345678901234567x"));
		assert(test2("00000000000000000000.00000012345678901234567",                "0.00000012345678901234566x"));
		assert(test2("00000000000000000000.0000012345678901234567",                 "0.0000012345678901234567x"));
		assert(test2("00000000000000000000.000012345678901234567",                  "0.000012345678901234568x"));

		assert(test2("00000000000000000000.00012345678901234567",                   "0.00012345678901234567x"));
		assert(test2("00000000000000000000.00123456789012345678",                   "0.0012345678901234567x"));
		assert(test2("00000000000000000000.01234567890123456789",                   "0.012345678901234568x"));
		assert(test2("00000000000000000000.12345678901234567890",                   "0.12345678901234568x"));
		assert(test2("00000000000000000001.23456789012345678901",                   "1.2345678901234567x"));
		assert(test2("00000000000000000012.34567890123456789010",                  "12.345678901234567x"));
		assert(test2("00000000000000000123.45678901234567890100",                 "123.45678901234568x"));
		assert(test2("00000000000000001234.56789012345678901000",                "1234.567890123457x"));
		assert(test2("00000000000000012345.67890123456789010000",               "12345.678901234567x"));
		assert(test2("00000000000000123456.78901234567890100000",              "123456.78901234567x"));

		assert(test2("00000000000001234567.89012345678901000000",             "1234567.8901234567x"));
		assert(test2("00000000000012345678.90123456789010000000",            "12345678.901234567x"));
		assert(test2("00000000000123456789.01234567890100000000",           "123456789.01234567x"));
		assert(test2("00000000001234567890.12345678901000000000",          "1234567890.1234567x"));
		assert(test2("00000000012345678901.23456789010000000000",         "12345678901.234568x"));
		assert(test2("00000000123456789012.34567890100000000000",        "123456789012.34567x"));
		assert(test2("00000001234567890123.45678901000000000000",       "1234567890123.4568x"));
		assert(test2("00000012345678901234.56789010000000000000",      "12345678901234.568x"));
		assert(test2("00000123456789012345.67890100000000000000",     "123456789012345.67x"));
		assert(test2("00001234567890123456.78901000000000000000",    "1234567890123456.8x"));
		assert(test2("00012345678901234567.89010000000000000000",   "12345678901234568x"));
		assert(test2("00123456789012345678.90100000000000000000",  "123456789012345680x"));
		assert(test2("01234567890123456789.01000000000000000000", "1234567890123456800x"));
		assert(test2("12345678901234567890.10000000000000000000","12345678901234567000x"));

#else //not USE_RYU_D2S
		assert(test2("00000000000000000000.000000000000000000012345678901234567",   "0.00000000000000000001234567890123457x"));
		assert(test2("00000000000000000000.00000000000000000012345678901234567",    "0.0000000000000000001234567890123457x"));
		assert(test2("00000000000000000000.0000000000000000012345678901234567",     "0.000000000000000001234567890123457x"));
		assert(test2("00000000000000000000.000000000000000012345678901234567",      "0.00000000000000001234567890123457x"));
		assert(test2("00000000000000000000.00000000000000012345678901234567",       "0.0000000000000001234567890123457x"));
		assert(test2("00000000000000000000.0000000000000012345678901234567",        "0.000000000000001234567890123457x"));
		assert(test2("00000000000000000000.000000000000012345678901234567",         "0.00000000000001234567890123457x"));
		assert(test2("00000000000000000000.00000000000012345678901234567",          "0.0000000000001234567890123457x"));
		assert(test2("00000000000000000000.0000000000012345678901234567",           "0.000000000001234567890123457x"));
		assert(test2("00000000000000000000.000000000012345678901234567",            "0.00000000001234567890123457x"));
		assert(test2("00000000000000000000.00000000012345678901234567",             "0.0000000001234567890123457x"));
		assert(test2("00000000000000000000.0000000012345678901234567",              "0.000000001234567890123457x"));
		assert(test2("00000000000000000000.000000012345678901234567",               "0.00000001234567890123457x"));
		assert(test2("00000000000000000000.00000012345678901234567",                "0.0000001234567890123457x"));
		assert(test2("00000000000000000000.0000012345678901234567",                 "0.000001234567890123457x"));
		assert(test2("00000000000000000000.000012345678901234567",                  "0.00001234567890123457x"));

		assert(test2("00000000000000000000.00012345678901234567",                   "0.0001234567890123457x"));
		assert(test2("00000000000000000000.00123456789012345678",                   "0.001234567890123457x"));
		assert(test2("00000000000000000000.01234567890123456789",                   "0.01234567890123457x"));
		assert(test2("00000000000000000000.12345678901234567890",                   "0.1234567890123457x"));
		assert(test2("00000000000000000001.23456789012345678901",                   "1.234567890123457x"));
		assert(test2("00000000000000000012.34567890123456789010",                  "12.34567890123457x"));
		assert(test2("00000000000000000123.45678901234567890100",                 "123.4567890123457x"));
		assert(test2("00000000000000001234.56789012345678901000",                "1234.567890123457x"));
		assert(test2("00000000000000012345.67890123456789010000",               "12345.67890123457x"));
		assert(test2("00000000000000123456.78901234567890100000",              "123456.7890123457x"));

		assert(test2("00000000000001234567.89012345678901000000",             "1234567.890123457x"));
		assert(test2("00000000000012345678.90123456789010000000",            "12345678.90123457x"));
		assert(test2("00000000000123456789.01234567890100000000",           "123456789.0123457x"));
		assert(test2("00000000001234567890.12345678901000000000",          "1234567890.123457x"));
		assert(test2("00000000012345678901.23456789010000000000",         "12345678901.23457x"));
		assert(test2("00000000123456789012.34567890100000000000",        "123456789012.3457x"));
		assert(test2("00000001234567890123.45678901000000000000",       "1234567890123.457x"));
		assert(test2("00000012345678901234.56789010000000000000",      "12345678901234.57x"));
		assert(test2("00000123456789012345.67890100000000000000",     "123456789012345.7x"));
		assert(test2("00001234567890123456.78901000000000000000",    "1234567890123457x"));
		assert(test2("00012345678901234567.89010000000000000000",   "12345678901234570x"));
		assert(test2("00123456789012345678.90100000000000000000",  "123456789012345700x"));
		assert(test2("01234567890123456789.01000000000000000000", "1234567890123457000x"));
		assert(test2("12345678901234567890.10000000000000000000","12345678901234570000x"));
#endif
	}

	{
		printl("Test consecutive numbers at maximum precision from 1.234567890123450 to 1.234567890123509");

		printl((var(1.234567890123450) ^ "x") , "1.23456789012345x");

		assert((var(1.234567890123450) ^ "x") == "1.23456789012345x");//0
		assert((var(1.234567890123451) ^ "x") == "1.234567890123451x");
		assert((var(1.234567890123452) ^ "x") == "1.234567890123452x");
		assert((var(1.234567890123453) ^ "x") == "1.234567890123453x");
		assert((var(1.234567890123454) ^ "x") == "1.234567890123454x");
		assert((var(1.234567890123455) ^ "x") == "1.234567890123455x");
		assert((var(1.234567890123456) ^ "x") == "1.234567890123456x");
		assert((var(1.234567890123457) ^ "x") == "1.234567890123457x");
		assert((var(1.234567890123458) ^ "x") == "1.234567890123458x");
		assert((var(1.234567890123459) ^ "x") == "1.234567890123459x");
		assert((var(1.234567890123460) ^ "x") == "1.23456789012346x");//0
		assert((var(1.234567890123461) ^ "x") == "1.234567890123461x");
		assert((var(1.234567890123462) ^ "x") == "1.234567890123462x");
		assert((var(1.234567890123463) ^ "x") == "1.234567890123463x");
		assert((var(1.234567890123464) ^ "x") == "1.234567890123464x");
		assert((var(1.234567890123465) ^ "x") == "1.234567890123465x");
		assert((var(1.234567890123466) ^ "x") == "1.234567890123466x");
		assert((var(1.234567890123467) ^ "x") == "1.234567890123467x");
		assert((var(1.234567890123468) ^ "x") == "1.234567890123468x");
		assert((var(1.234567890123469) ^ "x") == "1.234567890123469x");
		assert((var(1.234567890123470) ^ "x") == "1.23456789012347x");//0
		assert((var(1.234567890123471) ^ "x") == "1.234567890123471x");
		assert((var(1.234567890123472) ^ "x") == "1.234567890123472x");
		assert((var(1.234567890123473) ^ "x") == "1.234567890123473x");
		assert((var(1.234567890123474) ^ "x") == "1.234567890123474x");
		assert((var(1.234567890123475) ^ "x") == "1.234567890123475x");
		assert((var(1.234567890123476) ^ "x") == "1.234567890123476x");
		assert((var(1.234567890123477) ^ "x") == "1.234567890123477x");
		assert((var(1.234567890123478) ^ "x") == "1.234567890123478x");
		assert((var(1.234567890123479) ^ "x") == "1.234567890123479x");
		assert((var(1.234567890123480) ^ "x") == "1.23456789012348x");//0
		assert((var(1.234567890123481) ^ "x") == "1.234567890123481x");
		assert((var(1.234567890123482) ^ "x") == "1.234567890123482x");
		assert((var(1.234567890123483) ^ "x") == "1.234567890123483x");
		assert((var(1.234567890123484) ^ "x") == "1.234567890123484x");
		assert((var(1.234567890123485) ^ "x") == "1.234567890123485x");
		assert((var(1.234567890123486) ^ "x") == "1.234567890123486x");
		assert((var(1.234567890123487) ^ "x") == "1.234567890123487x");
		assert((var(1.234567890123488) ^ "x") == "1.234567890123488x");
		assert((var(1.234567890123489) ^ "x") == "1.234567890123489x");
		assert((var(1.234567890123490) ^ "x") == "1.23456789012349x");//0
		assert((var(1.234567890123491) ^ "x") == "1.234567890123491x");
		assert((var(1.234567890123492) ^ "x") == "1.234567890123492x");
		assert((var(1.234567890123493) ^ "x") == "1.234567890123493x");
		assert((var(1.234567890123494) ^ "x") == "1.234567890123494x");
		assert((var(1.234567890123495) ^ "x") == "1.234567890123495x");
		assert((var(1.234567890123496) ^ "x") == "1.234567890123496x");
		assert((var(1.234567890123497) ^ "x") == "1.234567890123497x");
		assert((var(1.234567890123498) ^ "x") == "1.234567890123498x");
		assert((var(1.234567890123499) ^ "x") == "1.234567890123499x");
		assert((var(1.234567890123500) ^ "x") == "1.2345678901235x");//00
		assert((var(1.234567890123501) ^ "x") == "1.234567890123501x");
		assert((var(1.234567890123502) ^ "x") == "1.234567890123502x");
		assert((var(1.234567890123503) ^ "x") == "1.234567890123503x");
		assert((var(1.234567890123504) ^ "x") == "1.234567890123504x");
		assert((var(1.234567890123505) ^ "x") == "1.234567890123505x");
		assert((var(1.234567890123506) ^ "x") == "1.234567890123506x");
		assert((var(1.234567890123507) ^ "x") == "1.234567890123507x");
		assert((var(1.234567890123508) ^ "x") == "1.234567890123508x");
		assert((var(1.234567890123509) ^ "x") == "1.234567890123509x");
	}

	//default is (d)ouble thankfully not (f)loat
	printl(var(1e-11f));
	printl(var(1e-11d));
	printl(var(1e-12f));
	printl(var(1e-12d));
	printl(var(1e-13f));
	printl(var(1e-13d));
	printl(var(1e-14f));
	printl(var(1e-14d));
	//0.000000000009999999960041972
	//0.000000000009999999999999999
	//0.0000000000009999999960041972
	//0.000000000001
	//0.000000000000099999998245167
	//0.0000000000001
	//0.0000000000000099999998245167
	//0.00000000000001

	assert(var(1e-11) == "0.00000000001");
	assert(var(1e-12) == "0.000000000001");
	assert(var(1e-13) == "0.0000000000001");
	assert(var(1e-14) == "0");//comparing to zero is special (diff less than 0.0001)

	assert(var(1e-11f).toString() == "0.000000000009999999960041972");
	printl(var(1e-11d));
#ifndef USE_RYU_D2S
	assert(var(1e-11d).toString() == "0.000000000009999999999999999");
#else
	assert(var(1e-11d).toString() == "0.00000000001");//ryu
#endif
	assert(var(1e-12f).toString() == "0.0000000000009999999960041972");
	assert(var(1e-12 ).toString() == "0.000000000001");
	assert(var(1e-13f).toString() == "0.000000000000099999998245167");
	assert(var(1e-13 ).toString() == "0.0000000000001");
	assert(var(1e-14f).toString() == "0.0000000000000099999998245167");
	assert(var(1e-14 ).toString() == "0.00000000000001");

	for (int i=-1000; i<=1000; ++i) {
		std::stringstream ss;
		ss << i;
		assert((var(i) ^ "x") == ss.str() + "x");
	}

	printl("Checking -101.00 to +101.00 in steps of 0.01");
	var started = ostime();
	for (double d=-101.00; d<=101.00; d+=0.01) {
		std::stringstream ss;
		ss.precision(2);
		ss << std::fixed << d;
		var v {d};
		v=round(v,2);
		if ((v ^ "x") != ss.str() + "x") {
			TRACE(d)
			TRACE(ss.str())
			TRACE(v)
			assert((v ^ "x") == ss.str() + "x");
		}
	}
	var msecs = (ostime()-started)*1000;
	printl(msecs,"msecs");

	// 1/1 to 1/10^20
	for (var i=0; i<30; ++i) {
		printl(i,var(pwr(10,-i)));
		printl(i,var(1/pwr(10,i)));
	}

	TRACE(var(pwr(10,-26)))
	TRACE(var(1/pwr(10,26)))
	TRACE(var(pwr(10,-26)) - var(1/pwr(10,26)))
	TRACE(var(pwr(10,-26)) == var(1/pwr(10,26)))

	assert((var(pwr(10,-26)) ^ "x") =="0.00000000000000000000000001x");//better calculation of 10^-26
	assert((var(1/pwr(10,26)) ^ "x") =="0.000000000000000000000000009999999999999999x");//poorer calculation of 1/10^26

	printl(((var(pwr(10,-26)) - var(1/pwr(10,26))) ^ "x"));
#ifndef USE_RYU_D2S
	assert(((var(pwr(10,-26)) - var(1/pwr(10,26))) ^ "x") == "0.000000000000000000000000000000000000000001434929627468613x");
#else
	assert(((var(pwr(10,-26)) - var(1/pwr(10,26))) ^ "x") == "0.0000000000000000000000000000000000000000014349296274686127x");//ryu
#endif
	assert(var(pwr(10,-26)) == var(1/pwr(10,26)));

	assert((var(pwr(10,-26)) ^ "x")  == "0.00000000000000000000000001x");
	assert((var(1/pwr(10,26)) ^ "x") == "0.000000000000000000000000009999999999999999x");
	assert((var(pwr(10,-27)) ^ "x")  == "0.000000000000000000000000001x");

	printl("Test passed");

	return 0;
}

subroutine out() {
		printl("code  : ", dv2);
		std::cout << "cout  :  " << std::fixed << std::setprecision(50) << dd1 << std::endl;
		printl("print : ", dv1);
		printl("concat: ", sv1);
		printl("Target: ", sv2);
}

function test2(const std::string str1, const std::string str2 = std::string()) {
	dd1 = stod(str1);
	dv1 = dd1;
	dv2 = str1;
	sv1 = dv1 ^ "x";
	var pad = (dd1>=0) ? " " : "";
	print(pad,str1,"->",pad,sv1,"target:",pad,str2);
	//printf(" printf:  %.17g\n", dd1);
	//print(std::format("{:10g}", dd1);
	osflush();
	//gosub out();

	if (str2.size()) {
		//assert(sv1 == str2);
		if (sv1 == str2) {
			printl(""," PASS");

			//also test negative
			if (str1[0] != '-') {
				return test2("-" + str1, "-" + str2);
			}

		} else {
			printl(" FAIL");
			return false;
		}
	} else
		printl(" UNTESTED");

	return true;
}

programexit()

