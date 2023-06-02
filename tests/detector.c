#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <signal.h>

int main() {
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        int* ptr = NULL;
        *ptr = 42; // Causes a segmentation fault
        return 0;
    } else {
        // Parent process
        int status;
        waitpid(child_pid, &status, 0);

        if (WIFSTOPPED(status) && WSTOPSIG(status) == SIGSEGV) {
            // Segmentation fault occurred

            // Attach to the child process
            ptrace(PTRACE_ATTACH, child_pid, NULL, NULL);
            waitpid(child_pid, &status, 0);

            if (WIFSTOPPED(status)) {
                struct user_regs_struct regs;

                // Get the current register values
                ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);

                // Print debug information
                printf("Child process received a segmentation fault:\n");
                printf("Program Counter: %lx\n", regs.eip);
                printf("Segmentation Fault Address: %lx\n", regs.cr2);

                // You can also use ptrace to examine memory contents
                // For example, to print 16 bytes of memory starting from the fault address
                for (int i = 0; i < 4; i++) {
                    long data = ptrace(PTRACE_PEEKDATA, child_pid, regs.cr2 + i * sizeof(long), NULL);
                    printf("Memory at %lx: %lx\n", regs.cr2 + i * sizeof(long), data);
                }

                // Detach from the child process
                ptrace(PTRACE_DETACH, child_pid, NULL, NULL);
            }
        }
    }

    return 0;
}

