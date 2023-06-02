#include <stdio.h>
#include <stdlib.h>


int main(){
	char buf[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	printf("frame pointer: %p\n", __builtin_frame_address(0));
	printf("return address before: %p\n", __builtin_return_address(0));
}
