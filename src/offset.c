#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

#include <sys/wait.h>
#include <sys/types.h>

#define PATTERN_SIZE 500
#define READ 0
#define WRITE 1

char* get_eip(){
	FILE* fp = popen("dmesg | grep -oP \"ip .* sp\" | sed \"s/\\(ip \\)\\(.*\\)\\( sp\\)/\\2/g\" | tail -n1", "r");
	char* eip = (char*)calloc(9, 1);
	fread(eip, 1, 8, fp); //this one doesnt matter
	fread(eip, 1, 8, fp);
	return eip;
}

char* generate_pattern(int len){
	char* pattern = (char*)calloc(len+2, 1);
	//generate the pattern here
	int i = 0;
	char cur_byte[] = "\x41\x41\x41\x41\x00";
	//65-122
	while(i < len){
		strcat(pattern, cur_byte);
		if(++cur_byte[3] >= 122){
			cur_byte[3] = 65;
			if(++cur_byte[2] >= 122){
				cur_byte[2] = 65;
				if(++cur_byte[1] >= 122){
					cur_byte[1] = 65;
					if(++cur_byte[0] >= 122){
						printf("pattern generation exceeded inital buffer\n");
						exit(1);
					}
				}
			}
		}
		i+=4;
	}
	pattern[len] = '\n';
	return pattern;
}

int calculate_offset(char* pattern, char* eip){
	int offset = 0;
	int eipInt = (int) strtol(eip, NULL, 16);
	while( eipInt != *((int*)(pattern+offset)) ){
		offset += 1;
	}
	return offset;
}


void find_offset(char* prgrm){
	//setup pipes
	int pipes[2];
	pipe(pipes);

	int child = fork();
	
	// CHILD
	if (child == 0) {
		//redirect stdin
		close(pipes[WRITE]);
		dup2(pipes[READ], STDIN_FILENO);
		printf("running targeted program...\n=========================================\n\n");

		char cmd[10000] = "./";
		strcat(cmd, prgrm);
		system(cmd);
	}

	// PARENT
	else {
		//send pattern to child process
		close(pipes[READ]);
		char* pattern = generate_pattern(PATTERN_SIZE);
		write(pipes[WRITE], pattern, strlen(pattern));

		//wait for program to crash
		int status;
		wait(&status);
		while( !WIFEXITED(status) ){
			wait(&status);
		}
		//printf("program crashed!\n");

		//calculate the offset
		char* eip = get_eip();
		printf("eip: %s\n", eip);
		int offset = calculate_offset(pattern, eip);
		printf("\n============================================\nTHE OFFSET IS: %d\n", offset);
	}
}
