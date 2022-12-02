//CALC (Commission Calculator) V1.0
//CrystalCraft Studios 2022

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void process(char **tokenCommand, int wordCount) {
    float nsfwTax = 3.00;
    float stdRate = 0.03;
    float disRate = 0.02;
    float rate = 0.00;
    float price = 0.00;

    if(!strcmp(tokenCommand[1], "y")) {
        price += nsfwTax;
    }

    if(!strcmp(tokenCommand[2], "y\n")) {
        rate = disRate;
    } 
    else {
        rate = stdRate;
    }

    price += wordCount * rate;
    printf("Price: %.2f\n", price);
    printf("Current price per word: %.2f\n", rate);
    printf("Has NSFW: %s \n", tokenCommand[1]);
    if(!strcmp(tokenCommand[1], "y")) {
        printf("NSFW tax: %.2f\n", nsfwTax);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    //Version data
    if(argc >= 2 && !strcmp(argv[1], "-v")) {
        printf("CALC        |V1.0\n");
        return 0;
    }
    
    char *command = NULL;
    char delim[] = " ";
    char *tokenCommand[3] = {};

    int wordCount = 0;
    
    while(1) {
        printf("C=");
        size_t length = 128;
        getline(&command, &length, stdin);

        char *ptr = strtok(command, delim);
        int i = 0;
        while(ptr != NULL) {
            tokenCommand[i] = ptr;
            ptr = strtok(NULL, delim);
            i++;
            if(i > 3) {
                printf("\nToo many values, erasing excess\n");
                break;
            }
        }
        if(!strcmp(tokenCommand[0], "help\n")) {
            printf("\nCommand format:\n[int wordCount] [NSFW (y/n)] [discount (y/n)]\n[exit] - exit calc\n[help] - display help guide\n\n");
        } 
        else if(!strcmp(tokenCommand[0], "exit\n")) {
            free(command);
            return 0;
        }
        else {
            wordCount = atoi(tokenCommand[0]);
            if(wordCount == 0) {
                printf("Error: WC cannot be 0 or ASCII! Type [help] for help!\n\n");
            }
            else {
                process(tokenCommand, wordCount);
            }
        }
    }
}