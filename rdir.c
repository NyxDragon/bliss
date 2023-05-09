//RDIR v1.0
//CrystalCraft Studios 2022

#include <ctype.h>                                          //Include the ctype.h header file
#include <stdio.h>                                          //Include the stdio.h header file   
#include <stdlib.h>                                         //Include the stdlib.h header file
#include <string.h>                                         //Include the string.h header file

#ifdef __WIN32                                              //If the operating system is Windows;
#define rdir "rmdir "                                       //Set the rdir variable to "rmdir "
#else                                                       //Otherwise
#define rdir "rm -r "                                       //Set the rdir variable to "rm -r "
#endif

int main(int argc, char **argv) {                           //Main function; starting up with the arguments provided, and the count of arguments provided.
   if(argc >= 2 && !strcmp(argv[1], "-v")) {                //Execute if flag is provided, and flag is "-v"
        printf("RDIR        |V1.0   |\n");                  //Print the version information
        return 0;                                           //Exit without error
    } 
    else if(argc >= 2) {                                    //Otherwise, if the argument count is 2 or more;
        char dir[256] = rdir;                               //Define a new character named dir with an arbitrary length and set its contents to the rdir variable we defined earlier
        strcat(dir, argv[1]);                               //Append the contents of argv[1] to dir
        system(dir);                                        //Execute the command we just made
    }
    else printf("No directory path provided!\n");           //Otherwise, print an error message
    return 0;                                               //Exit without error
}