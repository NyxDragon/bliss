//MDIR v1.0
//CrystalCraft Studios 2022-24

#include <ctype.h>                                          //Include the ctype.h header file
#include <stdio.h>                                          //Include the stdio.h header file
#include <stdlib.h>                                         //Include the stdlib.h header file
#include <string.h>                                         //Include the string.h header file

#ifdef __WIN32                                              //If the operating system is Windows;
#define mdir "md "                                          //Define mdir as "md "
#else                                                       //Otherwise
#define mdir "mkdir "                                       //Define mdir as "mkdir "
#endif

int main(int argc, char **argv) {                           //Main function; starting up with the arguments provided, and the count of arguments provided.
   if(argc >= 2 && !strcmp(argv[1], "-v")) {                //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("MDIR        |V1.0   |\n");                  //Print the version information
        return 0;                                           //Exit without error
    } 
    else if(argc >= 2) {                                    //Otherwise, if the argument count is 2 or more;
        char dir[256] = mdir;                               //Define a new character named dir with an arbitrary length, setting its default value to be the mdir variable predefined
        strcat(dir, argv[1]);                               //Append argv[1] to dir
        system(dir);                                        //Execute the command we just made
    }
    else printf("No directory path provided!\n");           //If no conditions are met, print an error
    return 0;                                               //Exit without error (This is not a part of the if/then statement, as the else printf statement is self-closing)
}