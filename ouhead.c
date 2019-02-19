#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    FILE *file; // file collected from stdin
    char *usage = "usage: ouhead [-n N] <file>";
    int lines = 0;
    char x;
    int N = 10;

    if(argc == 2) {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "File does not exist");
            return EXIT_FAILURE;
        }
        else {
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
    else if (!strcmp(argv[1], "-n") && argv[3]) {
        N = atoi(argv[2]);
        file = fopen(argv[3], "r");
        if (file == NULL) {
            fprintf(stderr, "File does not exist");
            return EXIT_FAILURE;
        }
        else {
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
    else if (!strcmp(argv[1], "-n")) {
        N = atoi(argv[2]);
        //file = stdin;
        //file = fopen(argv[3], "r");
        if (stdin == NULL) {
            fprintf(stderr, "File does not exist");
            return EXIT_FAILURE;
        }
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

