//RC V1.0
//CrystalCraft Studios 2022

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("RC          |V1.0\n");
        return 0;
    }

    if (argv[1][strlen(argv[1]) - 1] == '\n') argv[1][strlen(argv[1]) - 1] = '\0'; //strip newline char from command if present

    char *appslist = "data/apps.txt"; //path to appslist
    FILE *openFile = fopen(appslist, "r");
    if(!openFile) {
        printf("\nError opening 'data/apps.txt': File not found.\nERROR APPS-00\n\n");
    }
    char bufferA[256];
    if(!strcmp(argv[1], "all")) { //print all app info from apps.txt
      while(fgets(bufferA, sizeof(bufferA), openFile)) { //read line of text and make it run info command
        if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0'; //strip newline char from lines
        char cmd[512] = "gcc ";
        strcat(cmd, bufferA);
        strcat(cmd, ".c -o ");
        strcat(cmd, bufferA);
        system(cmd);
      }
    }
    else {
      while(fgets(bufferA, sizeof(bufferA), openFile)) { //read line of text and compare to input command
        if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0'; //strip newline char from lines

        if(!strcmp(argv[1], bufferA)) {
          char cmd[512] = "gcc ";
          strcat(cmd, bufferA);
          strcat(cmd, ".c -o ");
          strcat(cmd, bufferA);
          system(cmd);
        }
      }
    }
    fclose(openFile);
    return 0;
}
