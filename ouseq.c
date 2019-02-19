#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    
    int number1 = 0;
    int number2 = 0;
    char *usage = "usage: ouseq [M] N";
    
    // print usage statement
    if (!strcmp(argv[1], "-h")) {
        fprintf(stdout,"%s\n", usage);
        return EXIT_SUCCESS;
    }
    
    if(!argv[1]) {
        fprintf(stderr, "no numbers entered\n");
        return EXIT_FAILURE;
    }
    
    if(argv[1]) {
        number1 = atoi(argv[1]);
    }
    if(argv[2]) {
        number2 = atoi(argv[2]);
    }
    
    if(!argv[2]) {
        for(int i = 0; i <= number1; i++) {
            fprintf(stdout, "%d\n", i);
        }
        return EXIT_SUCCESS;
    }
    
    else if(number1 < number2) {
        for(int i = number1; i <= number2; i++) {
            fprintf(stdout, "%d\n", i);
        }
        return EXIT_SUCCESS;
    }
    
    else if(number1 > number2) {
        for(int i = number1; i >= number2; i--) {
            fprintf(stdout, "%d\n", i);
        }
        return EXIT_SUCCESS;
    }
    
    else if(number1 == number2) {
        fprintf(stdout,"%d\n", number1);
        return EXIT_SUCCESS;
    }
    
    fprintf(stderr, "an error has occured\n");
    return EXIT_FAILURE;

}

