#include <sys/ptrace.h>
#include <s
#include <unistd.h>
#include <stdio.h>
#include <sys/user.h>

/*
Some things to take a look at:

- ptrace()
	- allows parent process to view and contorl the execution + memory of a child process

- <linux/user.h>
	- has info about the registers here 

*/

int main(){
	printf("parent pid: %d\n", getpid());
	int pid = fork();

	//child
	if(pid == 0){
		while(1){
		}
		
	}


	return 0;
}
