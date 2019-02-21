#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// program used to print contents of the file or the string passed in

int main(int argc, const char * argv[]) {
    
    char* usage = "usage: oucat <files>"; // usage statement
    FILE *file; // file collected from stdin
    int printies; // print from file
    
    // if no arguments passed
    if (!argv[1]) {
        if (stdin == NULL) {
            // prints until EOF
            while ((printies = fgetc(stdin)) != EOF)
            {
                fprintf(stdout, "%c", printies);
            }
        }
        // prints from stdin until EOF
        for (char x = getc(stdin); x != EOF; x = getc(stdin)) {
            fprintf(stdout, "%c", x);
            }
        return EXIT_SUCCESS;
        }
    
    
    // print usage statement
    if (!strcmp(argv[1], "-h")) {
        fprintf(stdout,"%s\n", usage);
        return EXIT_SUCCESS;
    }
    
    // if at least one argument exists
    else if(argv[1]) {
        for(int i = 1; i < argc; i++) {
            // read from file to see whether or not it exists
            file = fopen(argv[i], "r");
            // if file does not exist ERROR
            if (file == NULL) {
                fprintf(stderr, "File does not exist");
                return EXIT_FAILURE;
            }
                // else file does exist print file contents
                else {
                    // prints from file until EOF
                    while ((printies = fgetc(file)) != EOF)
                    {
                        fprintf(stdout, "%c", printies);
                    }
                    fclose(file);
                }
            }
        return EXIT_SUCCESS;
        }
    
    fprintf(stderr, "%s\n", usage);
    return EXIT_FAILURE;
}

