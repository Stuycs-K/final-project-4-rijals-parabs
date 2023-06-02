#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>

int main() {
    pid_t child_pid;
    child_pid = fork();
    
    if (child_pid == 0) {
        // Child process
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl("./simple", "simple", NULL);
    } 

	else {
        // Parent process
        //wait(NULL);
        struct user_regs_struct regs;
        long return_address;

        // Attach to the child process
        ptrace(PTRACE_ATTACH, child_pid, NULL, NULL);
        wait(NULL);

        // Get the current register values
        ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);
		printf("ESP: %lx\nEBP: %lx\n", regs.esp, regs.ebp);

        // Obtain the return address from the stack
		for(int i = 0; i < 200; i++){
        	return_address = ptrace(PTRACE_PEEKTEXT, child_pid, (void *)(regs.esp + i*4), NULL);
        	printf("Return Address at %lx: %lx\n", (regs.esp+i*4), return_address);
		}

        // Detach from the child process
        ptrace(PTRACE_DETACH, child_pid, NULL, NULL);
		wait(NULL);
    }

    return 0;
}

