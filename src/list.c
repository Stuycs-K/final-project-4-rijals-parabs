#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get_functions(char* program_name){
  int len = strlen(program_name);
  char cmd[100] = "readelf -s ";
  strcat(cmd, program_name);
  strcat(cmd," | awk '($4 == \"FUNC\") && ($3 != 0)'");
  printf("%s\n", cmd);
  system(cmd);
}
