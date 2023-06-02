#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void help(){
	  printf(
          "./tool --help\n"
	  "List all the functions of this tool"
          "\n\n"
	  "./tool find-offset <prgm>\n"
	  "Find the offset for when you start overriding the pointer"
          "\n\n"
	  "./tool override-return <prgm> <offset> <new-return-address>\n"
	  "Use this to override the return address and modify it to a new one"
          "\n\n"
	  "./tool list-functions <prgm>\n"
	  "List all the functions and addresses"
	  "\n"
	  );
}

