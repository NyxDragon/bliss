//LIST v1.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
   if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("LIST        |V1.0\n");
        return 0;
    }
    system("ls");
    return 0;
}
