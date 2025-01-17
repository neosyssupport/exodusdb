#undef NDEBUG //because we are using assert to check actual operations that cannot be skipped in release mode testing
#include <cassert>
#include <cmath>

#include <exodus/program.h>
programinit()

function main() {
	printl("test_math says 'Hello World!'");

	gosub test_basic_ops();
	gosub test_mod();

	printl("Test passed");

	return 0;
}

subroutine test_mod() {

//a	b	exodus	arev	remainder
var moddata = R"(
-2	-2	0	0	0
-2	-1.5	-0.5	-0.5	-0.5
-2	-1	0	0	0
-2	-0.5	0	0	0
-2	0.5	0	0	0
-2	1	0	0	0
-2	1.5	1	1	-0.5
-2	2	0	0	0
-1.5	-2	-1.5	-1.5	0.5
-1.5	-1.5	0	0	0
-1.5	-1	-0.5	-0.5	0.5
-1.5	-0.5	0	0	0
-1.5	0.5	0	0	0
-1.5	1	0.5	0.5	0.5
-1.5	1.5	0	0	0
-1.5	2	0.5	0.5	0.5
-1	-2	-1	-1	-1
-1	-1.5	-1	-1	0.5
-1	-1	0	0	0
-1	-0.5	0	0	0
-1	0.5	0	0	0
-1	1	0	0	0
-1	1.5	0.5	0.5	0.5
-1	2	-1	1	-1
-0.5	-2	-0.5	-0.5	-0.5
-0.5	-1.5	-0.5	-0.5	-0.5
-0.5	-1	-0.5	-0.5	-0.5
-0.5	-0.5	0	0	0
-0.5	0.5	0	0	0
-0.5	1	0.5	0.5	-0.5
-0.5	1.5	1	1	-0.5
-0.5	2	1.5	1.5	-0.5
0	-2	0	0	0
0	-1.5	0	0	0
0	-1	0	0	0
0	-0.5	0	0	0
0	0.5	0	0	0
0	1	0	0	0
0	1.5	0	0	0
0	2	0	0	0
0.5	-2	-1.5	-1.5	0.5
0.5	-1.5	-1	-1	0.5
0.5	-1	-0.5	-0.5	0.5
0.5	-0.5	0	0	0
0.5	0.5	0	0	0
0.5	1	0.5	0.5	0.5
0.5	1.5	0.5	0.5	0.5
0.5	2	0.5	0.5	0.5
1	-2	1	-1	1
1	-1.5	-0.5	-0.5	-0.5
1	-1	0	0	0
1	-0.5	0	0	0
1	0.5	0	0	0
1	1	0	0	0
1	1.5	1	1	-0.5
1	2	1	1	1
1.5	-2	-0.5	-0.5	-0.5
1.5	-1.5	0	0	0
1.5	-1	-0.5	-0.5	-0.5
1.5	-0.5	0	0	0
1.5	0.5	0	0	0
1.5	1	0.5	0.5	-0.5
1.5	1.5	0	0	0
1.5	2	1.5	1.5	-0.5
2	-2	0	0	0
2	-1.5	-1	-1	0.5
2	-1	0	0	0
2	-0.5	0	0	0
2	0.5	0	0	0
2	1	0	0	0
2	1.5	0.5	0.5	0.5
2	2	0	0	0)";

	moddata.converter("\n\r\t",FM^FM^VM);
	for (var line: moddata) {
		if (not line)
			continue;
		printl(line);
#define USE_PICKOS_MODULUS
#ifdef USE_PICKOS_MODULUS
		assert(line.a(1,1)%line.a(1,2) == line.a(1,3));
#else
		assert(line.a(1,1)%line.a(1,2) == line.a(1,5));
#endif
		assert(std::remainder(line.a(1,1).toDouble(),line.a(1,2).toDouble()) == line.a(1,5));
	}

	return;
}

subroutine test_basic_ops() {

	//test all combinations of doubles and integers
	test("102.5","5.7");
	test("102"  ,"5.7");
	test("102.5","5");
	test("102"  ,"5");
	return ;
}

subroutine test(in as, in bs) {

	//test all combinations of negatives
	test2(as       ,       bs);
	test2("-" ^ as ,       bs);
	test2(as       , "-" ^ bs);
	test2("-" ^ as , "-" ^ bs);

	return;
}

subroutine test2(in as, in bs) {

	var z;
	var ai=as;
	var bi=bs;
	printl(as,ai.toInt(),round(as,0));
	//debug();
	printl(bs,bi.toInt(),round(bs,0));
	//assert(ai.toInt() == round(as,0));
	//assert(bi.toInt() == round(bs,0));
	ai.toInt();
	bi.toInt();

	var va,vb,vc;

	//plus
	va=ai;
	vb=bi;
	vc=va+vb;
	z=as+bs;
	printl(va,"+",vb,"=",vc,"add should be",z, vc == z ? "ok" : "FAIL");
	assert(vc == z);

	//multiply
	va=ai;
	vb=bi;
	vc=va*vb;
	z=as*bs;
	printl(va,"*",vb,"=",vc,"mul should be",z, vc == z ? "ok" : "FAIL");
	assert(vc == z);

	//minus
	va=ai;
	vb=bi;
	vc=va-vb;
	z=as-bs;
	printl(va,"-",vb,"=",vc,"sub should be",z, vc == z ? "ok" : "FAIL");
	assert(vc == z);

	//divide
	va=ai;
	vb=bi;
	vc=va/vb;
	z=as/bs;
	printl(va,"/",vb,"=",vc,"div be",z, vc == z ? "ok" : "FAIL");
	assert(vc == z);

	//modulus
	va=ai;
	vb=bi;
	vc=va%vb;
	z=as%bs;
	printl(va,"%",vb,"=",vc,"mod be",z, vc == z ? "ok" : "FAIL");
	assert(vc == z);

	return;
}

programexit()

