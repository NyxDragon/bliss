//Apps V1.0
//CrystalCraft Studios 2023-24

#include <ctype.h>                              //Include the ctype.h header file
#include <stdio.h>                              //Include the stdio.h header file
#include <stdlib.h>                             //Include the stdlib.h header file
#include <string.h>                             //Include the string.h header file

int main(int argc, char **argv) {               //Main function; starting up with the arguments provided, and the count of arguments provided.
   if(argc >= 2 && !strcmp(argv[1], "-v")) {    //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("HELP        |V1.1   |\n");      //Print the version information
        return 0;                               //Exit without error
    } 
    system("./outf data/apps.txt");             //Run the outf applet with a target file of data/apps.txt
    printf("\n");                               //Print a blank line
    return 0;                                   //Exit without error
}
