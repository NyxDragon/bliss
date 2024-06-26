/*******************************************************************************
 * BLISS Version 1.0 POSIX Compliant Edition                                   *
 *                                                                             *
 * Copyright 2023-24, CrystalCraft Studios                                     *
 * Permission is hereby granted, free of charge, to any person obtaining a copy*
 * of this software and associated documentation files (the "Software"), to    *
 * deal in the Software without restriction, including, without limitation the *
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or *
 * sell copies of the Software, and to permit persons to whom the Software is  *
 * furnished to do so, subject to the following conditions:                    *
 *                                                                             *
 * The above copyright notice and this permission notice shall be included in  *
 * all copies or substantial portions of the Software.                         *
 *                                                                             *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
 * IMPLIED, INCLUDING, BUT NOT LIMITED TO THE WARRANTIES OF NONINFRINGEMENT. IN*
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,    *
 * DAMAGES OR OTHER LIABILITY, WETHER IN AN ACTION OF CONTRACT, TORT OR        *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE   *
 * USE OR OTHER DEALINGS IN THE SOFTWARE.                                      *
 *******************************************************************************/

#include <ctype.h>                                                                                                      //Include the ctype.h header file
#include <stdio.h>                                                                                                      //Include the stdio.h header file
#include <stdlib.h>                                                                                                     //Include the stdlib.h header file
#include <string.h>                                                                                                     //Include the string.h header file

void splash() {                                                                                                         //Begin the splash routine
    system("clear");                                                                                                    //Clear the screen to start with a clean terminal
    printf("BLISS Version 1.0            | CrystalCraft Studios 2022 - 24\n");                                          //Print version information and developer information
    printf("-----------------------------+--------------------------------------------------\n\n");                     //Print ASCII text box border
}

int main(int argc, char **argv) {                                                                                       //Main function; starting up with the arguments provided, and the count of arguments provided.
    if(argc >= 2 && !strcmp(argv[1], "-v")) {                                                                           //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("BLISS       |V1.0   |\n");                                                                              //Print the version information
        return 0;                                                                                                       //Exit without error
    }
    char *command = NULL;                                                                                               //Default the command to NULL, so no garbage is in it at start
    char delim[] = " ";                                                                                                 //Set the arbitrary delimiter character. I chose a space
    char *tokenCommand[2] = {};                                                                                         //Set the token-Command command to be an empty array with an arbitrary maximum length
    int found = 0;                                                                                                      //Set the application found variable to false, as if it were true, it'd always think the app is found

    splash();                                                                                                           //Run the splash routine

    while(1) {                                                                                                          //While 1 is 1, so run forever
        printf(">");                                                                                                   //Print the arbitrary prompt text
        size_t length = 128;                                                                                            //Set an arbitrary command character limit
        getline(&command, &length, stdin);                                                                              //Take user input as &command, with a length of &length, as standard input

        char *ptr = strtok(command, delim);                                                                             //Tokenize command
        int loopCounter = 0;                                                                                            //Set the loop counter to start counting at 0
        while(ptr != NULL) {                                                                                            //Run while the pointer isn't NULL
            tokenCommand[loopCounter] = ptr;                                                                            //Set token-Command at the loopCounter value to the current pointer
            ptr = strtok(NULL, delim);                                                                                  //Break the command at the delimiter
            loopCounter ++;                                                                                             //Increment the loopCounter, keeping track of how many tokens we have
        }

        if (tokenCommand[0][strlen(tokenCommand[0]) - 1] == '\n') tokenCommand[0][strlen(tokenCommand[0]) - 1] = '\0';  //Strip newline char from command if present

        char *appslist = "data/apps.txt";                                                                               //Path to apps list
        FILE *openFile = fopen(appslist, "r");                                                                          //Open the app list
        if(!openFile) {                                                                                                 //If apps.txt is not found
            printf("\nError opening 'data/apps.txt': File not found, please replace and try again!");                   //Print the arbitrary "apps.txt not found" error.
        }
        else {                                                                                                          //Its an else... 
            if(!strcmp(tokenCommand[0], "exit")) {                                                                      //Exit terminal command
                printf("Quitting!\n");                                                                                  //Print the exit splash
                free(command);                                                                                          //Free the input variable to prevent memory leaks
                return 0;                                                                                               //Exit without error
            }
            else if(!strcmp(tokenCommand[0], "rc") && (tokenCommand[1] == NULL)) {                                      //Compile compiler applet command
                system("gcc rc.c -o rc");                                                                               //Run a predefined recompile command to compile the compiling utility with GCC
                found = 1;                                                                                              //Set the appFound variable to 1 for TRUE
            }
            else if(!strcmp(tokenCommand[0], "splash")) {                                                               //Run if command is splash
                splash();                                                                                               //Execute the splash routine
                found = 1;                                                                                              //Set the appFound variable to 1 for TRUE
            }
            else {
                char bufferA[256];                                                                                      //Set an arbitrary buffer length

                while(fgets(bufferA, sizeof(bufferA), openFile)) {                                                      //Read line of text and compare to input command
                    if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0';                       //Strip newline char from lines

                    if(!strcmp(tokenCommand[0], bufferA)) {                                                             //If user input = command name
                        found = 1;                                                                                      //Set the "App found" flag to 1 for TRUE
                        if(tokenCommand[1] != NULL) {                                                                   //Check if command has flag
                            char cmd[512] = "./";                                                                       //Append ./ to a command, allowing it to be run on POSIX-compliant systems
                            strcat(cmd, tokenCommand[0]);                                                               //Push command token 1 into the cmd variable
                            strcat(cmd, " ");                                                                           //Push a space between the program name and the flag
                            strcat(cmd, tokenCommand[1]);                                                               //This block puts commands in `cmd flag` format
                            system(cmd);                                                                                //Execute the command we made
                        }
                        else {                                                                                          //Execute if command has no flag
                            char cmd[512] = "./";                                                                       //Set the start of the syscmd as execute
                            strcat(cmd, tokenCommand[0]);                                                               //Append the first part of token-Command to the cmd variable
                            system(cmd);                                                                                //Execute the command we built. (Research new ways to do this that don't require a syscall)
                        }
                    }
                }
            }
            if (found == 1) found = 0;                                                                                  //Check if the app is in apps.txt
            else printf("\nApp Not Found in apps.txt!\n");                                                              //Print app not found error
            fclose(openFile);                                                                                           //Close the apps.txt file to ensure memory is clear as much as possible
                                            
            tokenCommand[0] = NULL;                                                                                     //Clear value of token-Command[0] to ensure you start fresh
            tokenCommand[1] = NULL;                                                                                     //Clear flag position 1 of token-Command to ensure you don't pass the last command's flag to the new command
        }
    }
}
