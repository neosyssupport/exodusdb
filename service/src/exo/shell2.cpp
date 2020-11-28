#include <exodus/library.h>

libraryinit()

function main(in cmd, out errors) {

	//var tempdir=std::experimental::filesystem::temp_directory_path().wstring();

	var tempdir="/tmp/";
	var tempfilename=tempdir ^ SLASH ^ rnd(99999999) ^ ".tmp";
	var output;
	output.osshellread(cmd^" 2> " ^ tempfilename);

	errors=osread(tempfilename);
	osdelete(tempfilename);

	return output;
}

libraryexit()

