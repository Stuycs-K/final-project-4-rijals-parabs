#include <stdlib.h>
#include <stdio.h>

int main(){
	printf("feed me!: \n");
	char buf[20];
	gets(buf);
	printf("output: %s\n", buf);
}
