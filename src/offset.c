#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>

#define READ 0
#define WRITE 1

void input_pattern(int len){
	printf("hello world!\n");
}

void find_offset(char* prgrm){
	//setup pipes
	int pipes[2];
	pipe(pipes);
	int fd = open("test.out", O_WRONLY | O_CREAT);

	int child = fork();
	
	// CHILD
	if (child == 0) {
		//redirect stdin
		close(pipes[WRITE]);
		dup2(pipes[READ], STDIN_FILENO);

		char cmd[10000] = "./";
		strcat(cmd, prgrm);
		system(cmd);
	}

	// PARENT
	else {
		//redirect stdout
		close(pipes[READ]);
		int tmp = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);

		//send the pattern payload
		input_pattern(100);

		//revert stdout
		dup2(tmp, STDOUT_FILENO);

		printf("got here!\n");
		//get the offset
		int status;
		wait(&status);
		while( !WIFEXITED(status) ){
			wait(&status);
		}
		printf("program crashed!\n");
	}
}
