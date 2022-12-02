//MDIR v1.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
#define mdir "md "
#else
#define mdir "mkdir "
#endif

int main(int argc, char **argv) {
   if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("MDIR        |V1.0\n");
        return 0;
    } 
    else if(argc >= 2) {
        char dir[256] = mdir;
        strcat(dir, argv[1]);
        system(dir);
    }
    else printf("No directory path provided!\n");
    return 0;
}