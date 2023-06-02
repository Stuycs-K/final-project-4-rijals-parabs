#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void help(){
	  printf(
      "./tool --help\n"
	  "List all the functions of this tool"
          "\n\n"
	  "./tool --offset <prgm>\n"
	  "Find the offset for when you start overriding the return address"
          "\n\n"
	  "./tool --override <prgm> <return-address> <offset>\n"
	  "Override the old return address to point to new one"
          "\n\n"
	  "./tool --list <prgm>\n"
	  "List all the functions their respective addresses"
	  "\n"
	  );
}

