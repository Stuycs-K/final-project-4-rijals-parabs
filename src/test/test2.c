#include <stdio.h>
#include <stdlib.h>


int main(){
	printf("return address before: %p\n", __builtin_return_address(0));
	char buf[10];
	gets(buf);
	printf("%s\n", buf);
	printf("return address after: %p\n", __builtin_return_address(0));
}
