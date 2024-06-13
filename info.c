//INFO v1.0
//CrystalCraft Studios 2022-24

#include <stdio.h>                                                                                    //Include the stdio.h header file
#include <stdlib.h>                                                                                   //Include the stdlib.h header file
#include <string.h>                                                                                   //Include the string.h header file

int main(int argc, char **argv) {                                                                     //Main function; starting up with the arguments provided, and the count of arguments provided.
    if (argc >= 2 && !strcmp(argv[1], "-v")) {                                                        //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("INFO        |V1.0   |\n");                                                            //Print the version information
        return 0;                                                                                     //Exit without error
    }

    //This is the new method! 
    if (argc == 1) printf("Usage: info [app name]\n");                                                //Output a notice if no input is given

    if (argv[1][strlen(argv[1]) - 1] == '\n') argv[1][strlen(argv[1]) - 1] = '\0';                    //Strip newline char from command if present

    char *appslist = "data/apps.txt";                                                                 //Define a new string with the contents "data/apps.txt"
    FILE *openFile = fopen(appslist, "r");                                                            //Define a FILE variable, named openfile, with the contents appslist as its value, and only allow it to be read from
    if(!openFile) printf("\nError opening 'data/apps.txt': File not found, please replace and try again!\n");//If the apps.txt file is not found, print error information
    
    char bufferA[256];                                                                                //Define a new bufferA variable with an arbitrary length
    if(!strcmp(argv[1], "all")) {                                                                     //Print all app info from apps.txt
      printf("APP         |Version|\n");                                                              //Print the table header ASCII art and text
      printf("------------+-------+\n");                                                              //Print the top of the ASCII art table
      while(fgets(bufferA, sizeof(bufferA), openFile)) {                                              //Read line of text and make it run info command
        if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0';                 //Strip newline char from lines
        char cmd[512] = "./";                                                                         //Define a new cmd variable with an arbitrary length and default text of "./"
        strcat(cmd, bufferA);                                                                         //Append bufferA's contents to the end of cmd
        strcat(cmd, " -v");                                                                           //Append " -v" to the end of cmd
        system(cmd);                                                                                  //Execute the command we just built (./appnName -v)
      }
      printf("------------+-------+\n");                                                              //Print the bottom of the ASCII art table
    }
    else {                                                                                            //Otherwise
      while(fgets(bufferA, sizeof(bufferA), openFile)) {                                              //Read line of text and compare to input command
        if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0';                 //Strip newline char from lines

        if(!strcmp(argv[1], bufferA)) {                                                               //If argv[1] is the same as bufferA's contents;
            char cmd[512] = "./";                                                                     //Set the start of the syscmd as "./"
            strcat(cmd, argv[1]);                                                                     //Append argv[1]'s contents to the end of cmd
            strcat(cmd, " -v");                                                                       //Append " -v" to the end of cmd
            printf("APP         |Version|\n");                                                        //Print the table header ASCII art and text
            printf("------------+-------+\n");                                                        //Print the top of the ASCII art table
            system(cmd);                                                                              //Execute the command we made
            printf("------------+-------+\n");                                                        //Print the bottom of the ASCII art table
        }
      }
    }
    fclose(openFile);                                                                                   //Close openFile, freeing memory
	printf("\n");                                                                                     //Print a blank line
	return 0;                                                                                         //Exit without error
}
