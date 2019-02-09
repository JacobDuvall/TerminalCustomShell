#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, const char * argv[]) {
    
    char holder[MAX_BUFFER]; //holds characters for various purposes
    FILE *file; //file pointer to hold special case file
    int number1 = 0; //used to hold number arguments
    int number2 = 0; //used to hold number arguments

    if (!strcmp(argv[1], "oucat")) {
        if(!argv[2]) {
            file = freopen(argv[1], "r", stdin); //reads batchfile as stdin
        }
        for(int i = 2; i < argc; i++) {
            if(access(argv[i],F_OK)!=-1) {
                strcat(holder,"cat ");
                strcat(holder,argv[i]);
                system(holder);
            }
            else {
                fprintf(stderr,"Not a file");
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }
    
    if (!strcmp(argv[1], "ouecho")) {
        if(!argv[2]) {
            fprintf(stdout,"\n");
        }
        for(int i = 2; i < argc; i++) {
            strcat(holder, "echo ");
            strcat(holder, argv[i]);
        }
        system(holder);
        return EXIT_SUCCESS;
    }
    
    if (!strcmp(argv[1], "ouhead")) {
        printf("ouhead");
    }
    
    if (!strcmp(argv[1], "outail")) {
        printf("outail");
    }
    
    if (!strcmp(argv[1], "ouseq")) {
        if(!argv[2]) {
            fprintf(stderr, "no numbers entered\n");
            return EXIT_FAILURE;
        }
        if(argv[2]) {
            number1 = atoi(argv[2]);
        }
        if(argv[3]) {
            number2 = atoi(argv[3]);
        }
        if(!argv[3]) {
            for(int i = 0; i <= number1; i++) {
                fprintf(stdout, "%d\n", i);
            }
            return EXIT_SUCCESS;
        }
        if(number1 < number2) {
            for(int i = number1; i <= number2; i++) {
                fprintf(stdout, "%d\n", i);
            }
            return EXIT_SUCCESS;
        }
        if(number2 < number1) {
            for(int i = number2; i >= number1; i--) {
                fprintf(stdout, "%d\n", i);
            }
            return EXIT_SUCCESS;
        }
        if(number1 == number2) {
            fprintf(stdout,"%d\n", number1);
            return EXIT_SUCCESS;
        }
        fprintf(stderr, "an error has occured\n");
        return EXIT_FAILURE;
    }
    
    if (!strcmp(argv[1], "ouwc")) {
        printf("ouwc");
    }
    
    return 0;
}
