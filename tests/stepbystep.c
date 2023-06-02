#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/syscall.h>
int main()
{   pid_t child;
    const int long_size = sizeof(long);
    child = fork();
    if(child == 0) {
		printf("execing child\n");
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl("./gets", "gets", NULL);
    }
    else {
        int status;
        union u {
            long val;
            char chars[long_size];
        }data;
        struct user_regs_struct regs;
        int start = 0;
        long ins;
        while(1) {
            wait(&status);
            if(WIFEXITED(status))
                break;
            ptrace(PTRACE_GETREGS,
                   child, NULL, &regs);
            if(start == 1) {
                ins = ptrace(PTRACE_PEEKTEXT,
                             child, regs.eip,
                             NULL);
                printf("EBP: %lx\nESP: %lx\nEIP: %lx Instruction "
                       "executed: %lx\n", regs.ebp, regs.esp,
                       regs.eip, ins);
				char buf[20];
				printf("CONT? ");
				gets(buf);
            }
            if(regs.orig_eax == SYS_write) {
                start = 1;
                ptrace(PTRACE_SINGLESTEP, child,
                       NULL, NULL);
            }
            else
                ptrace(PTRACE_SYSCALL, child,
                       NULL, NULL);
        }
    }
    return 0;
}
