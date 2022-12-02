//LIST v1.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
#define list "dir"
#else
#define list "ls"
#endif

int main(int argc, char **argv) {
   if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("LIST        |V1.0\n");
        return 0;
    }
    system(list);
    return 0;
}
