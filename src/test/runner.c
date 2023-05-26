#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void segfault_handler(int signum){
	printf("code %d\nthis program has segfaulted XD\n", signum);
	exit(1);
}

int main(){
	signal(SIGSEGV, segfault_handler);
	signal(SIGBUS, segfault_handler);

	//fork process and exec
	//get eip pointer at segfault for child process
	//send the eip pointer to parent

	char buf[10];
	gets(buf);

	/*
	int pid = fork()

	//child process
	if(pid == 0){
	}*/

}
