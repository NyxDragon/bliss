//EDIT v2.0
//CrystalCraft Studios 2022

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sys_cls "clear"

void save(char **page, int i) {
    char *filePath = NULL;
    system(sys_cls);
    printf("File to save: ");
    size_t length = 512;
    getline(&filePath, &length, stdin);
    
    filePath[strlen(filePath) -1] = '\0';
    FILE *openFile = fopen(filePath, "a");
    
    fseek(openFile, 0, SEEK_END);
    
    //save page
    int j = 0;
    while(j != i) {
        fputs(page[j], openFile);
        j++;
    }
    fclose(openFile);
    //clear page
    while(i!=0) {
        i--;
        free(page[i]);
    }
    free(filePath);
}

void editor(char **printLines) {
    system(sys_cls);
    
    char *line = NULL;
    char *page[1024] = {};

    printf("Edit V2.0 | x() - return to E= |\n");
    printf("----------+--------------------+------------------------------------------------\n");
    
    int k = 1;
    while(printLines[k] != NULL) {
        printf("%s", printLines[k]);
        k++;
    }

    int i = 0;
    while(1) {
        size_t length = 1024;
        getline(&line, &length, stdin);
        
        if(!strcmp(line, "x()\n")) {
            //clear page and escape
            while(i!=0) {
                i--;
                free(page[i]);
            }
            break;
        } 
        else if(!strcmp(line, "s()\n")) {
            save(page, i);
            break;
        }
        else {
            page[i] = strdup(line);
            i++;
        }
    }
}

void initLoad (char **printLines, char *filePath) {
    system(sys_cls);
    FILE *openFile = fopen(filePath, "r");
    if(!openFile) {
        printf("\nError opening file: Does not exist\n");
    }
    else {
        int i = 1;
        while(1) {
            char tempBuf[1024];
            if (!fgets(tempBuf, 1024, openFile)) break;
            printLines[i] = strdup(tempBuf);
            i++;
        }
        editor(printLines);
    }
}

void load(char **printLines) {
    char *filePath = NULL;
    system(sys_cls);
    printf("File to load: ");
    size_t length = 512;
    getline(&filePath, &length, stdin);

    filePath[strlen(filePath) -1] = '\0';
    FILE *openFile = fopen(filePath, "r");
    free(filePath);
    if(!openFile) {
        printf("\nError opening file: Does not exist\n");
    }
    else {
        
        int i = 1;
        while (1) {
            char tempBuf[1024];
            if (!fgets(tempBuf, 1024, openFile)) break;
            printLines[i] = strdup(tempBuf);
            i++;
        }
        editor(printLines);
    }
}

void help() {
    printf("\nE prompt commands\n");
    printf("-----+-------------------------------------------------------------------------+\n");
    printf("cls  | Clear terminal                                                          |\n");
    printf("new  | Edit new file                                                           |\n");
    printf("help | Help list                                                               |\n");
    printf("load | Load file                                                               |\n");
    printf("exit | Exit EDIT                                                               |\n");
    printf("----+--------------------------------------------------------------------------+\n");
    printf("\nEditor commands\n");
    printf("----+--------------------------------------------------------------------------+\n");
    printf("s() | Save                                                                     |\n");
    printf("x() | Return to E prompt                                                       |\n");
    printf("----+--------------------------------------------------------------------------+\n");
}

int main(int argc, char **argv) {
    //Version info
    if (argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("EDIT        |V2.0\n");
        return 0;
    }
    else if(argc >= 2) {
        char *printLines[1024] = {};
        char *filePath = strdup(argv[1]);
        initLoad(printLines, filePath);
    }
    else {
        char *printLines[1024] = {};
        char *command = NULL;

        while(1) {
            printf("E=");
            size_t length = 32;
            getline(&command, &length, stdin);

            if(!strcmp(command, "exit\n")) {
                return 0;
            } 
            else if(!strcmp(command, "cls\n")) {
                system(sys_cls);
            }
            else if(!strcmp(command, "new\n")) {
                editor(printLines);
            }
            else if(!strcmp(command, "help\n")) {
                help();
            }
            else if(!strcmp(command, "load\n")) {
                load(printLines);
            }
            else {
                printf("Unknown command.\n\n");
            }
        } 
    }
}