#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    // if no arguments
    if(!argv[1]) {
        fprintf(stdout, "\n");
        return EXIT_SUCCESS;
    }
    // else if arguments do exist
    else if(argv[1]) {
        // print arguments
        for(int i = 1; i < argc; i++) {
            fprintf(stdout, "%s", argv[i]);
            // only print spaces between arguments and not at the end
            if (i < argc -1) {
                fprintf(stdout, " ");
            }
        }
        //print new line after strings
        fprintf(stdout, "\n");
        return EXIT_SUCCESS;
    }
    else {
        return EXIT_FAILURE;
    }
    return EXIT_FAILURE;
}

