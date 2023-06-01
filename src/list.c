#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get_functions(char* prgrm){
  int len = strlen(prgrm);
  char cmd[100] = "readelf -s ";
  strcat(cmd, prgrm);
  strcat(cmd," | awk '($4 == \"FUNC\") && ($3 != 0)'");
  system(cmd);
}
