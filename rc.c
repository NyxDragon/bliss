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

    /*
    else if(argc >= 2 && !strcmp(argv[1], "h")) printf("Recompilable apps:\nALL\nCALC\nEDIT\nINFO\nMAN\nOUTF\n\n"); //outdated

    else if(argc >= 2 && !strcmp(argv[1], "all")) system("gcc cls.c -o cls && gcc calc.c -o calc && gcc del.c -o del && gcc edit.c -o edit && gcc help.c -o help && gcc info.c -o info && gcc list.c -o list && gcc mdir.c -o mdir && gcc man.c -o man && gcc outf.c -o outf && gcc rdir.c -o rdir");

    else if(argc >= 2 && !strcmp(argv[1], "cls")) system("gcc cls.c -o cls");
    else if(argc >= 2 && !strcmp(argv[1], "calc")) system("gcc calc.c -o calc");
    else if(argc >= 2 && !strcmp(argv[1], "del")) system("gcc del.c -o del");
    else if(argc >= 2 && !strcmp(argv[1], "edit")) system("gcc edit.c -o edit");
    else if(argc >= 2 && !strcmp(argv[1], "help")) system("gcc help.c -o help");
    else if(argc >= 2 && !strcmp(argv[1], "info")) system("gcc info.c -o info");
    else if(argc >= 2 && !strcmp(argv[1], "list")) system("gcc list.c -o list");
    else if(argc >= 2 && !strcmp(argv[1], "man")) system("gcc man.c -o man");
    else if(argc >= 2 && !strcmp(argv[1], "mdir")) system("gcc mdir.c -o mdir");
    else if(argc >= 2 && !strcmp(argv[1], "outf")) system("gcc outf.c -o outf");
    else if(argc >= 2 && !strcmp(argv[1], "rdir")) system("gcc rdir.c -o rdir");

    else printf("Not a known app\n");
    */
    return 0;
}
