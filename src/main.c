#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"


int main(int argc, char** argv){
	if( strcmp(argv[1], "--list")==0 ){
		get_functions(argv[2]);
	}

	else if( strcmp(argv[1], "--offset")==0 ){
		find_offset(argv[2]);
	}

	else if( strcmp(argv[1], "--override")==0 ){
		int offset = atoi(argv[4]); //convert string to int
		int retVal = (int) strtol(argv[3], NULL, 16); //convert hexstring to int
		override_return(argv[2], retVal, offset);
	}
	
	else if( strcmp(argv[1], "--help")==0 ){
		help();
	}

	else{
		printf("invalid option!\n");
	}

	
}
