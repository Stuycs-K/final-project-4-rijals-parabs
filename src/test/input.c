#include <stdio.h>

int main(){
	char buffer[32];
	gets(buffer);
	printf("%s\n", buffer);
}
