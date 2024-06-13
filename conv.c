/************************************************************
 * BLISS Video Converter Applet V1.0                        *
 * CrystalCraft Studios, 2023-24                            *
 * Requires FFMPEG to work, as well as h264!                *
 ************************************************************/
#include <stdio.h>                                                                  //Include the stdio.h header file
#include <dirent.h>                                                                 //Include the dirent.h header file
#include <string.h>                                                                 //Include the string.h header file
#include <stdlib.h>                                                                 //Include the stdlib.h header file

int main(int argc, char **argv) {                                                   //Main function; starting up with the arguments provided, and the count of arguments provided.
	if (argc >= 2 && !strcmp(argv[1], "-v")) {                                      //Run if application launches with a -v flag provided as the first argument, and an argument count of more than or equal to 2
        printf("CONV        |V1.0   |\n");                                          //Print the version information
        return 0;                                                                   //Exit without error
    }

    DIR *folder;                                                                    //Define a new DIR[ectory] variable named *folder
    struct dirent *entry;                                                           //Set structure dir[ectory]ent[ry] variable of *entry
    int files = 0;                                                                  //Set the file count to 0 to start
    folder = opendir("./convert/");                                                 //Open ./convert/ inside the folder variable, allowing us to work with it

    //                                                                                Set token char and token filename
    char delim[] = ".";                                                             //Define a delimiter of "."
    char *tokenFile[1] = {};                                                        //Define *tokenFile to an empty array with 1 entry
    char *inFile[32] = {};                                                          //Define inFile to an empty array with 32 entries
                                             
    if(folder == NULL) {                                                            //Check if current dir exists (Despite it being unlikely not to)
        perror("Unable to read directory");                                         //Display error if dir not found
        return(1);                                                                  //Exit with error
    }
                                                             
    while((entry=readdir(folder))) {                                                //Run command if and only if the dir isn't this dir, or up dir (options 1 and 2) or this file
        files++;                                                                    //Increment the file count
        if(files > 2 && strcmp(entry->d_name, "file")) {                            //Ensure we don't convert mp4 files to mp4 cus that'd be wasteful
            *inFile = strdup(entry->d_name);                                        //Create editiable copy of entry->d_name
            
                                                                                    //This block is to ignore mp4 files, as converting an mp4 to an mp4 is quite wasteful
            int len = strlen(entry->d_name);                                        //Get length of entry->d_name
            int fromstart = len - 3;                                                //Seek back 3 characters so file format can be read properly
            char formatName[3] = {};                                                //Define the 3 character format name space (E.G. mp4)
            int counter = 0;                                                        //Define a counter with a value of 0 to start
            while(counter != 3) {                                                   //Loop until a full 3 char file format is made (long enough for mp4 to be stored)
                char testMe = entry->d_name[fromstart];                             //Read one of the 3 final characters from d_name and hold it temporarily in testMe
                formatName[counter] = testMe;                                       //Copy the character currently loaded to the array of characters 
                counter ++;                                                         //Increment counter
                fromstart ++;                                                       //Increment fromstart
            }

            if(strcmp(formatName, "mp4")) {                                         //Check if file is mp4
                                                                                    //Build this command >> ffmpeg -i "[source][.fmt]" -c:v libx264 -preset fast "[source].mp4"
                char *ptr = strtok(*inFile, delim);                                 //tokenize the file name       
            
                char commandBase[256] = "ffmpeg -i \"convert/";                     //Set default command head
                char commandCore[128] = "\" -c:v libx264 -preset fast \"convert/";  //Tell ffmpeg what codec to use
                char format[128] = ".mp4\"";                                        //Tell ffmpeg what format to output
                strcat(commandBase, entry->d_name);                                 //Append the input file to the command head
                strcat(commandBase, commandCore);                                   //Append the codec flag to the command
                strcat(commandBase, ptr);                                           //Append the raw filename to the command
                strcat(commandBase, format);                                        //Append the output file format (mp4) to the command to finish it off
            
                //printf("%s\n", commandBase);                                      //Display command (for debugging)
                system(commandBase);                                                //Execute the command we built
            }
        }
    }

    closedir(folder);                                                               //Close the opened directory
    printf("\n\nDone!\n");                                                          //Completion text
    return(0);                                                                      //Close the application
}
