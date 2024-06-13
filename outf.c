//OUTF V1.0
//CrystalCraft Studios 2022-24

#include <ctype.h>                                                                         //Include the ctype.h header file
#include <stdio.h>                                                                         //Include the stdio.h header file
#include <stdlib.h>                                                                        //Include the stdlib.h header file
#include <string.h>                                                                        //Include the string.h header file

int main(int argc, char **argv) {                                                          //Main function; starting up with the arguments provided, and the count of arguments provided.
    if(argc >= 2 && !strcmp(argv[1], "-v")) {                                              //Execute if flag is provided, and flag is "-v"
        printf("OUTF        |V1.1   |\n");                                                 //Print version information
        return 0;                                                                          //End code without error
    }

    printf("File: %s\n\n", argv[1]);                                                       //Print the provided file name

    char *filePath = NULL;                                                                 //Init *char variable filePath with no contents
    filePath = strdup(argv[1]);                                                            //Duplicate the provided flat to the filePath variable (Kinda pointless but its safe) 
    
    FILE *openFile = fopen(filePath, "r");                                                 //Open file at filePath for Read Only
    free(filePath);                                                                        //Free memory used for filePath, preventing memory leaks
    
    if(!openFile) {                                                                        //Execute if there is no file found
    printf("\nError opening file: Does not exist.\n\n");                                   //Print error text (I could use perror if I knew how it worked)
    } 
    else {                                                                                 //Otherwise
        if (argv[1][strlen(argv[1]) - 1] == '\n') argv[1][strlen(argv[1]) - 1] = '\0';     //Strip newline char from command if present

        char readLine[1024];                                                               //Define a new variable with an arbitrary length named readLine
        while(fgets(readLine, sizeof(readLine), openFile)) {                               //Read line of text and compare to input command
        if(readLine[strlen(readLine) - 1] == '\n') readLine[strlen(readLine) - 1] = '\0';  //Strip newline char from lines
        printf("%s\n", readLine);                                                          //Yes, I know this undoes the newline that I just removed, buuuuuut its to ensure 100% of lines have one newline instead of having some lines have none and feel left out.
        }
    }
    return 0;                                                                              //End code without error
}