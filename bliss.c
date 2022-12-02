/*******************************************************************************
 * BLISS Version 1.0 POSIX Compliant Edition                                   *
 * CrystalCraft Studios 2022                                                   *
 *                                                                             *
 * This is free, open-source software, provided without a license. It comes as-*
 * is, with no warranty or guaranteed software support.                        *
 *******************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sys_cls "clear"

int main(int argc, char **argv) {
    //Version flag
    if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("BLISS       |V1.0\n");
        return 0;
    }
    char *command = NULL;
    char delim[] = " ";
    char *tokenCommand[2] = {};

    printf("BLISS Version 1.0            | CrystalCraft Studios 2022\n");
    printf("-----------------------------+--------------------------------------------------\n\n");

    while(1) {
        printf(":");
        size_t length = 128;                //Take input
        getline(&command, &length, stdin);

        char *ptr = strtok(command, delim); //Tokenize command
        int loopCounter = 0;
        while(ptr != NULL) {
            tokenCommand[loopCounter] = ptr;
            ptr = strtok(NULL, delim);
            loopCounter ++;
        }

        if (tokenCommand[0][strlen(tokenCommand[0]) - 1] == '\n') tokenCommand[0][strlen(tokenCommand[0]) - 1] = '\0'; //strip newline char from command if present

        char *appslist = "data/apps.txt"; //path to appslist
        FILE *openFile = fopen(appslist, "r");
        if(!openFile) {
            printf("\nError opening 'data/apps.txt': File not found.\nERROR APPS-00\n\n");
        }
        else {
            if(!strcmp(tokenCommand[0], "exit")) { //exit terminal command
                printf("Quitting!\n");
                free(command);
                return 0;
            }
            else if(!strcmp(tokenCommand[0], "rc") && (tokenCommand[1] == NULL)) { //compile compiler applet command
                system("gcc rc.c -o rc");
            }
            else {
                char bufferA[256];

                while(fgets(bufferA, sizeof(bufferA), openFile)) { //read line of text and compare to input command
                    if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0'; //strip newline char from lines

                    if(!strcmp(tokenCommand[0], bufferA)) {
                        if(tokenCommand[1] != NULL) { //check if command has flag
                            //if(tokenCommand[1][strlen(tokenCommand[1]) - 1] == '\n') tokenCommand[1][strlen(tokenCommand[0]) - 1] = '\0';
                            char cmd[512] = "./";
                            strcat(cmd, tokenCommand[0]);
                            strcat(cmd, " ");
                            strcat(cmd, tokenCommand[1]); //this block puts commands in `cmd flag` format
                            system(cmd);
                        }
                        else { //command has no flag set
                            char cmd[512] = "./"; //set the start of the syscmd as execute
                            strcat(cmd, tokenCommand[0]);
                            system(cmd);
                        }
                    }
                }
            }
            fclose(openFile);
            //ensure all tokens are clear before next input
           tokenCommand[0] = NULL;
           tokenCommand[1] = NULL;
        }
    }
}
