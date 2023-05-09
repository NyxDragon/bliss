//LIST v1.0
//CrystalCraft Studios 2022

#include <ctype.h>                                 //Include the ctype.h header file
#include <stdio.h>                                 //Include the stdio.h header file
#include <stdlib.h>                                //Include the stdlib.h header file
#include <string.h>                                //Include the string.h header file

#ifdef __WIN32                                     //If operating system is Windows;
#define list "dir"                                 //Define list as "dir"
#else                                              //Otherwise
#define list "ls"                                  //Define list as "ls"
#endif

int main(int argc, char **argv) {                  //Main function; starting up with the arguments provided, and the count of arguments provided.
   if(argc >= 2 && !strcmp(argv[1], "-v")) {       //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("LIST        |V1.0   |\n");         //Print the version information
        return 0;                                  //Exit without error
    }
    system(list);                                  //Run the list command we defined in precompiler code
    return 0;                                      //Exit without error
}
