//MAN V1.0
//CrystalCraft Studios 2022

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help() {
    printf("Available Commands:\n");
    printf("exit | Exits MANUAL\n");
    printf("help | Displays MANUAL help\n");
    printf("note | Displays Dev note\n");
    printf("gen  | Display general instructions\n");
    printf("1-6  | Displays section of defined number\n");
    printf("f1   | Displays Figure 1\n");
    printf("f2   | Displays Figure 2\n");
}

void note() {
    printf("__Note from The Developer______________________________________________________.\n");
    printf("This project is my first time writing C code, and is buggy as can be. I am     |\n");
    printf("learning C from very little programming experience with only the help of Google|\n");
    printf("and a friend who knows how to program in C. I cannot guarantee this project    |\n");
    printf("operates as intended on every machine, nor can I guarantee that this project is|\n");
    printf("entirely safe to run. I have had no issues with this project, but do note that |\n");
    printf("if you run this software, you are taking a risk. I haven't written any         |\n");
    printf("malicious code to my knowledge, but there could be bugs that overwrite parts of|\n");
    printf("your system's RAM or something.                                                |\n");
    printf("                                                                               |\n");
    printf("I don't know enough about how low-level code like C operates behind the scenes |\n");
    printf("to guarantee complete safety, nor that my warning is even needed. If you have a|\n");
    printf("copy of this code, odds are you are one of my friends who helped me figure out |\n");
    printf("how to build this code, so you know the risks, or lack there of.               |\n");
    printf("                                                                               |\n");
    printf("Happy computing!                                                               |\n");
    printf("-Sophie Spaan                                                                  |\n");
    printf("_______________________________________________________________________________.\n");
}

void gen() {
    printf("__General______________________________________________________________________.\n");
    printf("Please refer to the [help] command in BLISS for help during use, or execute    |\n");
    printf("[outf bliss-manual.txt] from the command line to display this page. This is the|\n");
    printf("primary help guide and instructions manual for BLISS. This file is to be       |\n");
    printf("included with every copy of BLISS for help.                                    |\n");
    printf("                                                                               |\n");
    printf("Please note that BLISS is not meant to replace any terminal software, and is   |\n");
    printf("only designed for experimentation, learning, and for myself (Sophie) to learn  |\n");
    printf("how to program in C. This software is not meant to be any sort of primary-use  |\n");
    printf("application, and is heavily limited due to my inexperience. Please do not      |\n");
    printf("install this software unless you understand this, and wish to see some beginner|\n");
    printf("C code.                                                                        |\n");
    printf("                                                                               |\n");
    printf("Once you compile the software, you are able to delete or move the .c files from|\n");
    printf("the BLISS folder, as they are unnecessary after compillation.                  |\n");
    printf("                                                                               |\n");
    printf("One more note: All commands are lower case, and case sensitive!                |\n");
    printf("_______________________________________________________________________________.\n");
}

void a() {
    printf("__Section 1: Compiling BLISS___________________________________________________.\n");
    printf("BLISS compiles with the GNU C Compiler (GCC), and all internal C compiler      |\n");
    printf("commands use GCC formatting. To compile BLISS with C, simply navigate to the   |\n");
    printf("folder you have BLISS downloaded (and decompressed) within, and run:           |\n");
    printf("                                                                               |\n");
    printf("[gcc bliss.c -o bliss]                                                         |\n");
    printf("                                                                               |\n");
    printf("This command will compile the BLISS command line. From there, you can execute: |\n");
    printf("                                                                               |\n");
    printf("[./bliss]                                                                      |\n");
    printf("                                                                               |\n");
    printf("This will launch the BLISS terminal. You will be greeted with a [B=] prompt.   |\n");
    printf("From the [B=] prompt, you must execute:                                        |\n");
    printf("                                                                               |\n");
    printf("[rc]                                                                           |\n");
    printf("[rc] [all]                                                                     |\n");
    printf("                                                                               |\n");
    printf("This command will compile all BLISS standard applets. Upon a successful        |\n");
    printf("execution, you will be greeted with just the text [Done!] If you have any      |\n");
    printf("errors, you will be greeted with the error code before the [Done!] message.    |\n");
    printf("                                                                               |\n");
    printf("*Note: If you do not use GCC, you will need to change all gcc commands in      |\n");
    printf("BLISS.c yourself to properly compile the BLISS applets, or manually compile    |\n");
    printf("every BLISS applet before execution.                                           |\n");
    printf("_______________________________________________________________________________.\n");
}

void b() {
    printf("__Section 2: BLISS help________________________________________________________.\n");
    printf("BLISS comes with a small selection of general-use applets and commands for     |\n");
    printf("general computation and word processing. At any time, you can run [help] to    |\n");
    printf("print off the BLISS help menu (Figure 1) in the terminal. Help also comes with |\n");
    printf("the ability to display command help, such as command formatting, and more      |\n");
    printf("descriptive explanations of the command's purpose. For example, if you execute:|\n");
    printf("                                                                               |\n");
    printf("[help] [outf]                                                                  |\n");
    printf("                                                                               |\n");
    printf("Your terminal will then display the following message:                         |\n");
    printf("                                                                               |\n");
    printf("Format: [outf] [pathToFile]                                                    |\n");
    printf("Outputs contents of file under [pathToFile]                                    |\n");
    printf("                                                                               |\n");
    printf("This explains the command formatting, in this case, you input [outf] space,    |\n");
    printf("and the file you desire to have printed to the terminal. Do note, the [] are   |\n");
    printf("simply there to show a single part of a command. An example of this command in |\n");
    printf("use would be as follows:                                                       |\n");
    printf("                                                                               |\n");
    printf("[outf] [bliss-manual.txt]                                                      |\n");
    printf("                                                                               |\n");
    printf("Upon execution of the above command, you will be greeted with this file's      |\n");
    printf("contents printed in your terminal window.                                      |\n");
    printf("_______________________________________________________________________________.\n");
}

void c() {
    printf("__Section 3: The EDIT text editor______________________________________________.\n");
    printf("EDIT is the included basic text editor application. It is incredibly simple,   |\n");
    printf("and heavily limited. It is more of a quick means to print text to a file,      |\n");
    printf("rather than a dedicated word processor application. Before you use EDIT, you   |\n");
    printf("must know that you cannot edit more than the line you are currently typing to. |\n");
    printf("This limitation may be problematic for most use cases.                         |\n");
    printf("                                                                               |\n");
    printf("To launch edit, simply execute:                                                |\n");
    printf("                                                                               |\n");
    printf("[edit]                                                                         |\n");
    printf("                                                                               |\n");
    printf("This will launch EDIT, and will greet you with the [E=] prompt. On this prompt,|\n");
    printf("you may type help for a help page (Figure 2) which gives a basic explanation of|\n");
    printf("all of the standard EDIT commands.                                             |\n");
    printf("                                                                               |\n");
    printf("To open a new file, execute:                                                   |\n");
    printf("                                                                               |\n");
    printf("[new]                                                                          |\n");
    printf("                                                                               |\n");
    printf("You will be greeted with the EDIT header, reminding you that [x()] exits the   |\n");
    printf("editor without saving. Type whatever you would like (Noting that x() and s()   |\n");
    printf("are system reserved) and hit enter to save the line to RAM. The cursor will    |\n");
    printf("return to the first character of the next line, allowing you to input another  |\n");
    printf("line of text.                                                                  |\n");
    printf("                                                                               |\n");
    printf("To save a file, type [s()] and click return, this will bring you to the save   |\n");
    printf("screen. From here, type the file path, name, and extension you wish to save to.|\n");
    printf("                                                                               |\n");
    printf("Example 1: ~/bliss/bliss-manual.txt                                            |\n");
    printf("Example 2: bliss-manual.txt                                                    |\n");
    printf("                                                                               |\n");
    printf("This will save the contents of your file to the defined file path. Do note the |\n");
    printf("line cannot be longer than 1023 characters, and a file can be no longer than   |\n");
    printf("1023 lines long in EDIT, otherwise crashes are likely. Also note that a file   |\n");
    printf("path can be no longer than 511 characters long in EDIT.                        |\n");
    printf("                                                                               |\n");
    printf("EDIT also supports the ability to load files into the editor window, allowing  |\n");
    printf("you to append to the end of the file. To load a file, from the [E=] prompt,    |\n");
    printf("type [load] and hit return. This will request a file to load from. Follow the  |\n");
    printf("same formatting from examples 1 and 2, and hit enter. This will automatically  |\n");
    printf("load the entire file to the terminal window, and move your cursor to a new line|\n");
    printf("in the file.                                                                   |\n");
    printf("                                                                               |\n");
    printf("To exit EDIT from the [E=] prompt, execute:                                    |\n");
    printf("                                                                               |\n");
    printf("[exit]                                                                         |\n");
    printf("                                                                               |\n");
    printf("This will return you to the [B=] prompt. To exit the editor window, type x(),  |\n");
    printf("and hit enter. This will return you to the [E=] prompt.                        |\n");
    printf("_______________________________________________________________________________.\n");
}

void d() {
    printf("__Section 4: Directory and file management commands____________________________.\n");
    printf("Directory and file management commands allow more control over your directories|\n");
    printf("and files, respectively. These commands can erase documents and directories, as|\n");
    printf("well as create directories.                                                    |\n");
    printf("                                                                               |\n");
    printf("To create a new directory, execute:                                            |\n");
    printf("                                                                               |\n");
    printf("[mdir] [path]                                                                  |\n");
    printf("                                                                               |\n");
    printf("Replace [path] with the directory you wish to create. To delete a directory,   |\n");
    printf("execute:                                                                       |\n");
    printf("                                                                               |\n");
    printf("[rdir] [path]                                                                  |\n");
    printf("                                                                               |\n");
    printf("Replace [path] with the directory you wish to delete permanently. Please note, |\n");
    printf("this is a permanent means of deleting a directory, and if misused, this command|\n");
    printf("can damage your operating system, so be careful with what you delete. To delete|\n");
    printf("a file, execute:                                                               |\n");
    printf("                                                                               |\n");
    printf("[del] [pathToFile]                                                             |\n");
    printf("                                                                               |\n");
    printf("In this case, replace [pathToFile] with the exact path and name of the file.   |\n");
    printf("Please note, if misused, this command can cause damage to your operating       |\n");
    printf("system, so be careful with what you delete.                                    |\n");
    printf("_______________________________________________________________________________.\n");
}

void e() {
    printf("__Section 5: CALC______________________________________________________________.\n");
    printf("CALC is an applet designed to calculate writing commission prices, since the   |\n");
    printf("developer is a writer as well, and is not generally intended for standard use, |\n");
    printf("although, this app can be used as a learning tool, or modified to your needs.  |\n");
    printf("It is a very simple applet. To use it as intended, execute:                    |\n");
    printf("                                                                               |\n");
    printf("[wordCount] [containsNTax] [isDiscounted]                                      |\n");
    printf("                                                                               |\n");
    printf("[wordCount] is simply an integer number of words to be expected within a piece,|\n");
    printf("which is billed at a rate of $0.03/wd. [containsNTax] is a value of [y] or [n] |\n");
    printf("and tracks if an additional $3.00 surcharge is to be added for various 'taxes' |\n");
    printf("to the writing piece. [isDiscounted] is a value of [y] or [n] and tracks if a  |\n");
    printf("piece is billed at the $0.02/wd rate.                                          |\n");
    printf("_______________________________________________________________________________.\n");
}

void f() {
    printf("__Section 6: INFO______________________________________________________________.\n");
    printf("INFO is a tool to display version data on any BLISS applet. To display all data|\n");
    printf("on all applets, execute:                                                       |\n");
    printf("                                                                               |\n");
    printf("[info]                                                                         |\n");
    printf("                                                                               |\n");
    printf("To run INFO on any individual app, simply execute the following:               |\n");
    printf("                                                                               |\n");
    printf("[info] [appName]                                                               |\n");
    printf("                                                                               |\n");
    printf("[appName] is to be replaced with the name of the applet you desire to know the |\n");
    printf("version of.                                                                    |\n");
    printf("_______________________________________________________________________________.\n");
}

void fa() {
    printf("__Figure 1: BLISS help menu____________________________________________________.\n");
    printf("General Commands\n");
    printf("+-------+----------------------------------------------------------------------+\n");
    printf("|cls    | Clear terminal                                                       |\n");
    printf("|calc   | Commissions price calculator                                         |\n");
    printf("|del    | Deletes file                                                         |\n");
    printf("|edit   | Launch BLEdit software                                               |\n");
    printf("|exit   | Ends BLISS session                                                   |\n");
    printf("|help   | Displays this guide OR input help [command] for specific help        |\n");
    printf("|info   | Displays current build information                                   |\n");
    printf("|list   | Lists current directory contents                                     |\n");
    printf("|mdir   | Make directory at filepath                                           |\n");
    printf("|outf   | Display file contents to terminal                                    |\n");
    printf("|rdir   | Removes directory at filepath                                        |\n");
    printf("|sys    | Runs non-BLISS command                                               |\n");
    printf("+-------+----------------------------------------------------------------------+\n");
    printf("\n");
    printf("Compiling Commands\n");
    printf("+-------+----------------------------------------------------------------------+\n");
    printf("|rcall  | Recompile all standard BLISS software                                |\n");
    printf("|rcc    | Recompile CALC                                                       |\n");
    printf("|rce    | Recompile EDIT                                                       |\n");
    printf("+-------+----------------------------------------------------------------------+\n");
}

void fb() {
    printf("__Figure 2: EDIT help menu_____________________________________________________.\n");
    printf("E prompt commands\n");
    printf("-----+-------------------------------------------------------------------------+\n");
    printf("cls  | Clear terminal                                                          |\n");
    printf("new  | Edit new file                                                           |\n");
    printf("help | Help list                                                               |\n");
    printf("load | Load file                                                               |\n");
    printf("exit | Exit EDIT                                                               |\n");
    printf("----+--------------------------------------------------------------------------+\n");
    printf("\n");
    printf("Editor commands\n");
    printf("----+--------------------------------------------------------------------------+\n");
    printf("s() | Save                                                                     |\n");
    printf("x() | Return to E prompt                                                       |\n");
    printf("----+--------------------------------------------------------------------------+\n");
}

int main(int argc, char **argv) {
    //Version information
    if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("MAN         |V1.0   |\n");
        return 0;
    }
    else if(argc >= 2 && !strcmp(argv[1], "help")) {
        help();
    }
    else if(argc >= 2 && !strcmp(argv[1], "note")) {
        note();
    }
    else if(argc >= 2 && !strcmp(argv[1], "gen")) {
        gen();
    }
    else if(argc >= 2 && !strcmp(argv[1], "1")) {
        a();
    }
    else if(argc >= 2 && !strcmp(argv[1], "2")) {
        b();
    }
    else if(argc >= 2 && !strcmp(argv[1], "3")) {
        c();
    }
    else if(argc >= 2 && !strcmp(argv[1], "4")) {
        d();
    }
    else if(argc >= 2 && !strcmp(argv[1], "5")) {
        e();
    }
    else if(argc >= 2 && !strcmp(argv[1], "6")) {
        f();
    }
    else if(argc >= 2 && !strcmp(argv[1], "f1")) {
        fa();
    }
    else if(argc >= 2 && !strcmp(argv[1], "f2")) {
        fb();
    }
    else {
        char *section = NULL;
        while(1) {
            printf("M=");
            size_t length = 16;
            getline(&section, &length, stdin);

            if(!strcmp(section, "exit\n")) {
                free(section);
                return 0;
            }
            else if(!strcmp(section, "help\n")) {
                help();
            }
            else if(!strcmp(section, "note\n")) {
                note();
            }
            else if(!strcmp(section, "gen\n")) {
                gen();
            }
            else if(!strcmp(section, "1\n")) {
                a();
            }
            else if(!strcmp(section, "2\n")) {
                b();
            }
            else if(!strcmp(section, "3\n")) {
                c();
            }
            else if(!strcmp(section, "4\n")) {
                d();
            }
            else if(!strcmp(section, "5\n")) {
                e();
            }
            else if(!strcmp(section, "6\n")) {
                f();
            }
            else if(!strcmp(section, "f1\n")) {
                fa();
            }
            else if(!strcmp(section, "f2\n")) {
                fb();
            }
        }
        return 0;
    }
}