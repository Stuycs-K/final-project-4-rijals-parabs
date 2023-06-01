#include <stdio.h>

void override_return(char* prgrm, char* newRet, int offset){
	printf("override return received: %s, %s, %d\n", prgrm, newRet, offset);
}
