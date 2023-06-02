#include <stdlib.h>
#include <stdio.h>

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>

void find_offset(char* prgrm){
	printf("find offset received: %s\n", prgrm);
}
