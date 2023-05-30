#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

/*
- print registers of own program
- print registers of another process
- print registers of inputted program
*/

void error_check(int err, char* msg){
	if (err == -1) {
		printf("ERROR at %s:\n%s\n", msg, strerror(errno));
		exit(1);
	}
}

int main(){
	//printf("parent pid: %d\n", getpid());	
	int tracee = fork();

	//traced process	
	if(tracee == 0){
		//printf("child pid: %d\n", getpid());
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		//execl("gets", "gets", NULL);
		printf("child's return address after %p\n", __builtin_return_address(0));

	}
	else{
		struct user_regs_struct regs;

		int res = ptrace(PTRACE_ATTACH, tracee, 0, 0);
		wait(NULL); //wait for attach

		printf("ATTACH returned: %d\n", res);
		error_check(res, "PTRACE_ATTACH");
		
		//get return address
		res = ptrace(PTRACE_GETREGS, tracee, 0, &regs);
		printf("GETREGS returned: %d\n", res);
		error_check(res, "GET_REGS");
		printf("esp returned: %lx\n", regs.esp);

		//resume execution
		ptrace(PTRACE_CONT, tracee, 0, 0);		
	}


}

