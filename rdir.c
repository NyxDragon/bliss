//RDIR v1.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
#define rdir "rmdir "
#else
#define rdir "rm -r "
#endif

int main(int argc, char **argv) {
   if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("RDIR        |V1.0\n");
        return 0;
    } 
    else if(argc >= 2) {
        char dir[256] = rdir;
        strcat(dir, argv[1]);
        system(dir);
    }
    else printf("No directory path provided!\n");
    return 0;
}