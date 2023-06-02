#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//it is usefull to add these definitions to make your code more readible
#define READ 0
#define WRITE 1

int main() {
  int fds[2];
  pipe( fds );
  char line[100];

  int f = fork();
  if (f == 0) {
    close( fds[READ] ); //it is a good idea to close the end of the pipe your are not using.
	int tmp = dup(STDOUT_FILENO);
	dup2(fds[WRITE], STDOUT_FILENO);
	printf("hello!\n");
	//dup2(tmp, STDOUT_FILENO);
	//printf("hello again!\n");
    //write( fds[WRITE], "hello!", 7);
  }
  else {
    close( fds[WRITE] );
    read( fds[READ], line, 3);
	printf("2nd: %s\n", line);
  }
}

