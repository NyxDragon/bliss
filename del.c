//DEL v1.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
#define delt "del "
#else
#define delt "rm "
#endif

int main(int argc, char **argv) {
   if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("DEL         |V1.0\n");
        return 0;
    }
    else if(argc >= 2) {
        char del[128] = delt;
        strcat(del, argv[1]);
        system(del);
    }
    else {
        printf("No file selected!\n");
    }
    return 0;
}
