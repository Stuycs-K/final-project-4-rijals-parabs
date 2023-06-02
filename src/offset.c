#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>

void print_pattern(){
}

void find_offset(char* prgrm){

	int child = fork();
	
	// CHILD
	if (child == 0) {
		char cmd[10000] = "./";
		strcat(cmd, prgrm);
		system(cmd);
	}

	// PARENT
	else {
		int status;
		wait(&status);
		while( !WIFEXITED(status) ){
			wait(&status);
		}
		printf("program crashed!\n");
	}
	
}
