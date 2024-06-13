//RC V1.0
//CrystalCraft Studios 2022-24

#include <stdio.h>                                                                                          //Include the stdio.h header file
#include <string.h>                                                                                         //Include the string.h header file
#include <stdlib.h>                                                                                         //Include the stdlib.h header file

int main(int argc, char **argv) {                                                                           //Main function; starting up with the arguments provided, and the count of arguments provided.
    if(argc >= 2 && !strcmp(argv[1], "-v")) {                                                               //Execute if flag is provided, and flag is "-v"
        printf("RC          |V1.0   |\n");                                                                  //Print the version information
        return 0;                                                                                           //Exit without error
    }

    if (argv[1][strlen(argv[1]) - 1] == '\n') argv[1][strlen(argv[1]) - 1] = '\0';                          //Strip newline char from command if present

    char *appslist = "data/apps.txt";                                                                       //Path to appslist
    FILE *openFile = fopen(appslist, "r");                                                                  //Open apps list file
    if(!openFile) {                                                                                         //Run if the apps file is not found
        printf("\nError opening 'data/apps.txt': File not found.\nPlease reinstall and try again!\n\n");
    }
    char bufferA[256];
    if(!strcmp(argv[1], "all")) {                                                                           //Print all app info from apps.txt
      while(fgets(bufferA, sizeof(bufferA), openFile)) {                                                    //Read line of text and make it run info command
        if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0';                       //Strip newline char from lines
        char cmd[512] = "gcc ";                                                                             //Command head- invokes GCC
        strcat(cmd, bufferA);                                                                               //Append the app name provided to command
        strcat(cmd, ".c -o ");                                                                              //Append the c extension and the output flag to the command
        strcat(cmd, bufferA);                                                                               //Append the app name to the command again, at the end
        system(cmd);                                                                                        //Execute the command we made
        printf(".");                                                                                        //Display a "." to show that a process is done!
      }
      printf("\n");                                                                                         //Print a newline to keep the prompt from displaying with the "."s
    }
    else {
      while(fgets(bufferA, sizeof(bufferA), openFile)) {                                                    //Read line of text and compare to input command
        if(bufferA[strlen(bufferA) - 1] == '\n') bufferA[strlen(bufferA) - 1] = '\0';                       //Strip newline char from lines

        if(!strcmp(argv[1], bufferA)) {                                                                     //Run if input file name is found in apps file
          char cmd[512] = "gcc ";                                                                           //Command head- invokes GCC
          strcat(cmd, bufferA);                                                                             //Append the app name provided to command
          strcat(cmd, ".c -o ");                                                                            //Append the c extension and the output flag to the command
          strcat(cmd, bufferA);                                                                             //Append the app name to the command again, at the end
          system(cmd);                                                                                      //Execute the command we made
        }
      }
    }
    fclose(openFile);                                                                                       //Close the apps file to free memory
    return 0;                                                                                               //Exit without error
}
