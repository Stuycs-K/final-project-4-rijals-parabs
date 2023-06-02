#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void getFlag(){
  printf("flag{cranberry}");
}

void main(int argc, char **argv){
  puts("Give string plz: ");
  char text[10];
  gets(text);
}

int add(int first, int second){
  int third = first + second;
  return 8;
}

void drive(){
  printf("You arrived at the supermarket");
}
