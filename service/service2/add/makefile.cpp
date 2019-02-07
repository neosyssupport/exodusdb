#include <exodus/library.h>
libraryinit()

function main() {

	var command=COMMAND.convert(FM," ").lcase();

	printl(command);

	command.swapper(" data "," ");
	command.swapper(" dict "," dict_");
	command.swapper(" dict."," dict_");

	printl(command);

	//something like DATAVOL\NEOS0001 will be ignored
	var volname=field(command," ",2);

	var filename=field(command," ",3);
	if (not filename) {
		filename=volname;
		volname="";
	}
	var file;
	//TODO support volume in createfile
	return osshell("createfile " ^ filename ^ " " ^ OPTIONS);
}

libraryexit()
