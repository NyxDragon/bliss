//CLS v1.0
//CrystalCraft Studios 2022

#include <ctype.h>                              //Include the ctype.h header file
#include <stdio.h>                              //Include the stdio.h header file
#include <stdlib.h>                             //Include the stdlib.h header file
#include <string.h>                             //Include the string.h header file

#ifdef __WIN32                                  //If the operating system is windows
#define cls "cls"                               //Set the cls variable in the actual code to cls
#else                                           //Otherwise
#define cls "clear"                             //Set the cls variable in the actual code to clear, to be POSIX compliant
#endif

int main(int argc, char **argv) {               //Main function; starting up with the arguments provided, and the count of arguments provided.
   if(argc >= 2 && !strcmp(argv[1], "-v")) {    //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("CLS         |V1.0   |\n");      //Print version information
        return 0;                               //Exit without error
    } 
    system(cls);                                //Execute the clear screen command
    return 0;                                   //Exit without error
}