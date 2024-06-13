//EDIT v2.0
//CrystalCraft Studios 2022-24

#include <ctype.h>                                                                                          //Include the ctype.h header file
#include <stdio.h>                                                                                          //Include the stdio.h header file
#include <stdlib.h>                                                                                         //Include the stdlib.h header file
#include <string.h>                                                                                         //Include the string.h header file

#define sys_cls "clear"                                                                                     //Define sys_cls in post-compile code to be replaced by precompiler with "clear"

void save(char **page, int i) {                                                                             //Start of the save function, look for array of arrays of characters page, and integer i
    char *filePath = NULL;                                                                                  //Define an array of characters with NULL contents
    system(sys_cls);                                                                                        //Tell host system to clear screen
    printf("File to save: ");                                                                               //Print a prompt
    size_t length = 512;                                                                                    //Define an arbitrary length
    getline(&filePath, &length, stdin);                                                                     //Define filePath to be user input with an arbitrary length as standard input
    
    filePath[strlen(filePath) -1] = '\0';                                                                   //Strip the newline character from the end of filePath and replace it with null
    FILE *openFile = fopen(filePath, "a");                                                                  //Define a FILE variable named openFile as the document at filePath as append
    
    fseek(openFile, 0, SEEK_END);                                                                           //Move cursor in openFile to the 0th character of the last line on the document
    
    //save page
    int j = 0;                                                                                              //Define an integer named j with a value of 0
    while(j != i) {                                                                                         //Whilst j is not equal to i
        fputs(page[j], openFile);                                                                           //Print the contents of the "j"th value of page into openFile
        j++;                                                                                                //Increment j
    }
    fclose(openFile);                                                                                       //Close the openFile document to prevent overwriting and clear memory
    //clear page
    while(i!=0) {                                                                                           //Whilst i is not 0;
        i--;                                                                                                //Decrement i
        free(page[i]);                                                                                      //Free the memory used by the "i"th value of the page variable to prevent memory leaks
    }
    free(filePath);                                                                                         //Free the memory used by the filePath variable to prevent memory leaks
}

void editor(char **printLines) {                                                                            //Start of the editor function, looking for array of arrays of characters printLines
    system(sys_cls);                                                                                        //Tell the host system to clear screen
    
    char *line = NULL;                                                                                      //Define an array of characters with a name of line and null contents
    char *page[1024] = {};                                                                                  //Define an array of arrays of characters with the name of page and an arbitrary length of 1024 and no default values

    printf("Edit V2.0 | x() - return to E= |\n");                                                           //Arbitrary text
    printf("----------+--------------------+------------------------------------------------\n");           //Arbitrary text
    
    int k = 1;                                                                                              //Define integer k to equal 1
    while(printLines[k] != NULL) {                                                                          //While the "k"th value of printLines is not null;
        printf("%s", printLines[k]);                                                                        //Output the "k"th value of printLines
        k++;                                                                                                //Increment k
    }

    int i = 0;                                                                                              //Set i to equal zero
    while(1) {                                                                                              //Infinite loop
        size_t length = 1024;                                                                               //Arbitrary maximum line length
        getline(&line, &length, stdin);                                                                     //Set line to equal user input with a length of length as standard input
        
        if(!strcmp(line, "x()\n")) {                                                                        //If line's contents are x()\n;
            //clear page and escape
            while(i!=0) {                                                                                   //Whilst i is not zero;
                i--;                                                                                        //Decrement i
                free(page[i]);                                                                              //Free the memory used by the "i"th value of the page variable to prevent memory leaks
            }
            break;                                                                                          //Break the loop
        } 
        else if(!strcmp(line, "s()\n")) {                                                                   //Otherwise, if user input is s()\n;
            save(page, i);                                                                                  //Run the save function providing the page and i variables
            break;                                                                                          //End the loop
        }
        else {                                                                                              //Otherwise;
            page[i] = strdup(line);                                                                         //Set the "i"th value of page to equal the contents of line
            i++;                                                                                            //Increment i
        }
    }
}

void initLoad (char **printLines, char *filePath) {                                                         //Start of initLoad function; looks for array of arrays of characters named printLines and array of characters filePath
    system(sys_cls);                                                                                        //Tell the host system to clear the screen
    FILE *openFile = fopen(filePath, "r");                                                                  //Define a FILE variable named openFile as the file at filePath as read
    if(!openFile) {                                                                                         //If openFile cannot be opened;
        printf("\nError opening file: Does not exist\n");                                                   //Print error information
    }
    else {                                                                                                  //Otherwise
        int i = 1;                                                                                          //Define an integer with a name of i and a value of 1
        while(1) {                                                                                          //Infinite loop
            char tempBuf[1024];                                                                             //Define an array of characters with a name of tempBuf and an arbitrary length
            if (!fgets(tempBuf, 1024, openFile)) break;                                                     //If openFile's contents cannot be placed into tempBuf, break the loop
            printLines[i] = strdup(tempBuf);                                                                //Define the "i"th value of printLines to equal tempBuf
            i++;                                                                                            //Increment i
        }
        editor(printLines);                                                                                 //Run editor function with printLines provided
    }
}

void load(char **printLines) {                                                                              //Start of the load function, accepting array of array of characters variable printLines
    char *filePath = NULL;                                                                                  //Clear filePath just to be safe
    system(sys_cls);                                                                                        //Tell host system to clear screen
    printf("File to load: ");                                                                               //Print a prompt
    size_t length = 512;                                                                                    //Set an arbitrary maximum length for user input
    getline(&filePath, &length, stdin);                                                                     //Update contents of filePath to equal user input with a length of length as standard input

    filePath[strlen(filePath) -1] = '\0';                                                                   //If a \n character is present in filePath, replace it with a null
    FILE *openFile = fopen(filePath, "r");                                                                  //Define a FILE variable named openFile as the file at filePath as read
    free(filePath);                                                                                         //Clear memory used for filePath variable to prevent memory leaks
    if(!openFile) {                                                                                         //If file cannot be opened;
        printf("\nError opening file: Does not exist\n");                                                   //Print error information
    }
    else {                                                                                                  //Otherwise
        int i = 1;                                                                                          //Define an integer i with a value of 1
        while (1) {                                                                                         //Infinite loop
            char tempBuf[1024];                                                                             //Define an array of characters named tempBuf with an arbitrary length
            if (!fgets(tempBuf, 1024, openFile)) break;                                                     //If not able to put value from openFile into tempBuf, break the loop
            printLines[i] = strdup(tempBuf);                                                                //Define the "i"th value in printLines as the contents of the tempBuf variable
            i++;                                                                                            //Increment the i variable
        }
        editor(printLines);                                                                                 //Run the editor routine with printLines provided
    }
}

void help() {                                                                                               //Start of the help routine
    printf("\nE prompt commands\n");                                                                        //Arbitrary text
    printf("-----+-------------------------------------------------------------------------+\n");           //Arbitrary text
    printf("cls  | Clear terminal                                                          |\n");           //Arbitrary text
    printf("new  | Edit new file                                                           |\n");           //Arbitrary text
    printf("help | Help list                                                               |\n");           //Arbitrary text
    printf("load | Load file                                                               |\n");           //Arbitrary text
    printf("exit | Exit EDIT                                                               |\n");           //Arbitrary text
    printf("----+--------------------------------------------------------------------------+\n");           //Arbitrary text
    printf("\nEditor commands\n");                                                                          //Arbitrary text
    printf("----+--------------------------------------------------------------------------+\n");           //Arbitrary text
    printf("s() | Save                                                                     |\n");           //Arbitrary text
    printf("x() | Return to E prompt                                                       |\n");           //Arbitrary text
    printf("----+--------------------------------------------------------------------------+\n");           //Arbitrary text
}

int main(int argc, char **argv) {                                                                           //Begin main function, providing the argument count, and the contents of argv
    if (argc >= 2 && !strcmp(argv[1], "-v")) {                                                              //If the argument count is 2 or more, and the second argument is "-v",
        printf("EDIT        |V2.0   |\n");                                                                  //Print version information
        return 0;                                                                                           //Exit without error
    }
    else if(argc >= 2) {                                                                                    //Otherwise, if the argument count is 2 or more;
        char *printLines[1024] = {};                                                                        //Define an array of arrays of characters named printlines with an arbitrary length and an empty array
        char *filePath = strdup(argv[1]);                                                                   //Define an array of characters named filePath with a starting value of the contents of argv[1]'s contents
        initLoad(printLines, filePath);                                                                     //Run initLoad with printLines and filePath provided
    }
    else {                                                                                                  //Otherwise
        char *printLines[1024] = {};                                                                        //Define an array of arrays of characters named printlines with an arbitrary length and an empty array
        char *command = NULL;                                                                               //Define an array of characters with the name command with a starting value of null

        while(1) {                                                                                          //Infinite loop
            printf("E=");                                                                                   //Print arbitrary command prompt header
            size_t length = 32;                                                                             //Set an arbitrary command length
            getline(&command, &length, stdin);                                                              //Read user input and put it in command with a length of length through standard input

            if(!strcmp(command, "exit\n")) return 0;                                                        //If command is exit, quit without error
            else if(!strcmp(command, "cls\n")) system(sys_cls);                                             //If command is cls, tell the system to clear the terminal
            else if(!strcmp(command, "new\n")) editor(printLines);                                          //If command is new, run the editor routine with printLines provided
            else if(!strcmp(command, "help\n")) help();                                                     //If command is help, run the help routine
            else if(!strcmp(command, "load\n")) load(printLines);                                           //If command is load, run the load routine with printLines provided
            else printf("Unknown command.\n\n");                                                            //Print error if command not found
        } 
    }
}