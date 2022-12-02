//OUTF V1.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    //Version data
    if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("OUTF        |V1.1\n");
        return 0;
    }

    printf("File: %s\n\n", argv[1]);

    char *filePath = NULL;
    filePath = strdup(argv[1]);
    
    FILE *openFile = fopen(filePath, "r");
    free(filePath);
    if(!openFile) {
    printf("\nError opening file: Does not exist.\n\n");
    }
    else {
        while(1) {
            char tempBuf[1024];
            if(!fgets(tempBuf, 1024, openFile)) break;
            printf("%s", tempBuf);
        }
        fclose(openFile);
        printf("\n");
    }
    return 0;
}