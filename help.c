//Help v1.1
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
   if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("HELP        |V1.1\n");
        return 0;
    } 
    system("./outf data/help.txt");
    return 0;
}