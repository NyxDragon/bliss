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
        if (argv[1][strlen(argv[1]) - 1] == '\n') argv[1][strlen(argv[1]) - 1] = '\0'; //strip newline char from command if present

        char readLine[1024];
        while(fgets(readLine, sizeof(readLine), openFile)) { //read line of text and compare to input command
        if(readLine[strlen(readLine) - 1] == '\n') readLine[strlen(readLine) - 1] = '\0'; //strip newline char from lines
        printf("%s\n", readLine); //Yes, I know this undoes the newline that I just removed, buuuuuut its to ensure 100% of lines have one newline instead of having some lines have none and feel left out.
        }
    }
    return 0;
}