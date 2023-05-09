//DEL v1.0
//CrystalCraft Studios 2022

#include <ctype.h>                                  //Include the ctype.h header file
#include <stdio.h>                                  //Include the stdio.h header file
#include <stdlib.h>                                 //Include the stdlib.h header file
#include <string.h>                                 //Include the string.h header file

#ifdef __WIN32                                      //If the operating system is Windows
#define delt "del "                                 //Define delt variable to be "del "
#else                                               //Otherwise
#define delt "rm "                                  //Define the delt variable to be "rm " to be POSIX compliant
#endif

int main(int argc, char **argv) {                   //Main function; starting up with the arguments provided, and the count of arguments provided.
   if(argc >= 2 && !strcmp(argv[1], "-v")) {        //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("DEL         |V1.0   |\n");          //Print the version information
        return 0;                                   //Exit without error
    }
    else if(argc >= 2) {                            //If the argument count is two or more
        char del[128] = delt;                       //Define character del with an arbitrary length to equal the value of delt
        strcat(del, argv[1]);                       //Append the second argument to del as a file name
        system(del);                                //Execute the command we built
    }
    else {                                          //If no filename provided
        printf("No file selected!\n");              //Print error
    }
    return 0;                                       //Exit without error
}
