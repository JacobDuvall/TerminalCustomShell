#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {
    
    char *usage = "usage: ouwc [-l | -c] <file>";
    FILE *file;
    char x;
    int lines = 0;
    int bytes = 0;
    char linesArr[100];
    char bytesArr[100];
    int lineCount = 0;
    int bytesCount = 0;
    
    
    // print usage statement
    if (!strcmp(argv[1], "-h")) {
        fprintf(stdout,"%s\n", usage);
        return EXIT_SUCCESS;
    }
    
    // if there is only one argument
    if(argv [0] && argv[1] && strcmp(argv[1], "-l") && strcmp(argv[1], "-c") && !argv[2]) {
        file = fopen(argv[1], "r");
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(file); x != EOF; x = getc(file)) {
                bytes = bytes + 1;
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d", lines);
            
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", bytes);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // else if there are -l and -c and file arguments
    else if (!strcmp(argv[1], "-l") && !strcmp(argv[2], "-c") && argv[3]) {
        file = fopen(argv[3], "r");
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(file); x != EOF; x = getc(file)) {
                bytes = bytes + 1;
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d", lines);
            
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", bytes);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // else if there are only -l and -c arguments
    else if (!strcmp(argv[1], "-l") && !strcmp(argv[2], "-c")) {
        if(stdin == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(stdin); x != EOF; x = getc(stdin)) {
                bytes = bytes + 1;
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d", lines);
            
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", bytes);
            
            fclose(stdin);
            return EXIT_SUCCESS;
        }
    }
    
    // else if -l and file arguments
    else if (!strcmp(argv[1], "-l") && argv[2]) {
        file = fopen(argv[2], "r");
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(file); x != EOF; x = getc(file)) {
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", lines);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // else if -c and file arguments
    else if (!strcmp(argv[1], "-c") && argv[2]) {
        file = fopen(argv[2], "r");
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(file); x != EOF; x = getc(file)) {
                bytes = bytes + 1;
            }

            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", bytes);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    //read from stdin for -c
    else if (!strcmp(argv[1], "-c")) {
        if(stdin == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(stdin); x != EOF; x = getc(stdin)) {
                bytes = bytes + 1;
            }
            
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", bytes);
            
            fclose(stdin);
            return EXIT_SUCCESS;
        }
    }
    
    //read from stdin for -l
    else if (!strcmp(argv[1], "-l")) {
        if(stdin == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(stdin); x != EOF; x = getc(stdin)) {
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            fprintf(stdout, "%d\n", lines);
            
            fclose(stdin);
            return EXIT_SUCCESS;
        }
    }

    
    else {
        fprintf(stderr, "an error occured");
        return EXIT_FAILURE;
    }

    
    return 0;
}

