/* AUTHOR: JACOB DUVALL
 *
 * DATE: 2/21/19
 *
 * PROGRAM: ouhead.c
 *
 * DESCRIPTION: Takes file names or standard input and prints the first n lines to standard out.
 *
 * Input Parameters:
 *      int argc : the number of parameters passed in
 *      const char * argv[] : the arguments backs in as an array of pointers
 *
 * Return: 
 *      EXIT_SUCCESS : The program exits as expected
 *      EXIT_FAILURE : The program terminates early because of a problem
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// program to read n lines from the file passed
int main(int argc, const char * argv[]) {
    
    FILE *file; // file collected from stdin
    char *usage = "usage: ouhead [-n N] <file>"; // usage statement
    int lines = 0; // line counter
    char x; // stores the file contents
    int N = 10; // number of lines to read
    
    if (argc == 1) {
        fprintf(stderr, "%s\n", usage);
        return EXIT_FAILURE;
    }

    // if only one argument
    if(argc == 2) {
        // open file for reading
        file = fopen(argv[1], "r");
        // if no file
        if (file == NULL) {
            fprintf(stderr, "File does not exist");
            return EXIT_FAILURE;
        }
        // if file opens
        else {
            // while file characters are not EOF
            for (x = getc(file); x != EOF; x = getc(file)) {
                if(lines != N) {
                    fprintf(stdout, "%c", x);
                    if (x == '\n') {
                        lines = lines + 1;
                    }
                }
            }
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // if -n and a file is passed
    else if (!strcmp(argv[1], "-n") && argv[3]) {
        N = atoi(argv[2]);
        // open file for reading
        file = fopen(argv[3], "r");
        // if no file
        if (file == NULL) {
            fprintf(stderr, "File does not exist");
            return EXIT_FAILURE;
        }
        // if file
        else {
            // while file is not EOF
            for (x = getc(file); x != EOF; x = getc(file)) {
                if(lines != N) {
                    fprintf(stdout, "%c", x);
                    if (x == '\n') {
                        lines = lines + 1;
                    }
                }
            }
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // if -n only
    else if (!strcmp(argv[1], "-n")) {
        N = atoi(argv[2]);
        // if stdin is NULL
        if (stdin == NULL) {
            fprintf(stderr, "File does not exist");
            return EXIT_FAILURE;
        }
        // if stdin is not NULL
        else {
            for (x = getc(stdin); x != EOF; x = getc(stdin)) {
                if(lines != N) {
                    fprintf(stdout, "%c", x);
                    if (x == '\n') {
                        lines = lines + 1;
                    }
                }
            }
            fclose(stdin);
            return EXIT_SUCCESS;
        }
    }
    
    // print usage statement
    if (!strcmp(argv[1], "-h")) {
        fprintf(stdout,"%s\n", usage);
        return EXIT_SUCCESS;
    }
    
    
    
    
    return 0;
}

