#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// program to print the number of lines and/or the number of bytes from a file
int main(int argc, const char * argv[]) {
    
    char *usage = "usage: ouwc [-l | -c] <file>"; // usage statement
    FILE *file; // file from stdin
    char x; // char to hold file chars
    int lines = 0; // line total
    int bytes = 0; // bytes total
    char linesArr[100]; // line array
    char bytesArr[100]; // bytes array
    int lineCount = 0; // line counter
    int bytesCount = 0; // bytes counter
    
    
    // print usage statement
    if (!strcmp(argv[1], "-h")) {
        fprintf(stdout,"%s\n", usage);
        return EXIT_SUCCESS;
    }
    
    // if there is only one argument
    if(argv [0] && argv[1] && strcmp(argv[1], "-l") && strcmp(argv[1], "-c") && !argv[2]) {
        // try to read file
        file = fopen(argv[1], "r");
        // if file does not exist
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        // if file exist
        else {
            // read from file until EOF
            for (x = getc(file); x != EOF; x = getc(file)) {
                // increment bytes
                bytes = bytes + 1;
                // if x is new line increment lines
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            // reads the number of digits in lines and stores in linecCount
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                //too many lines to display correctly
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            // reads the number of digits in bytes and stores in bytesCount
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                // too many bytes to display correctly
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            // print correct number of lines
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // prines number of lines
            fprintf(stdout, "%d", lines);
            
            // print correct number of bytes
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            // prints number of bytes
            fprintf(stdout, "%d\n", bytes);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // else if there are -l and -c and file arguments
    else if (!strcmp(argv[1], "-l") && !strcmp(argv[2], "-c") && argv[3]) {
        // read file
        file = fopen(argv[3], "r");
        // if cant read file
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        // if can read file
        else {
            // while file is not EOF
            for (x = getc(file); x != EOF; x = getc(file)) {
                bytes = bytes + 1;
                if (x == '\n') {
                    lines = lines + 1;
                }
            }
            
            // reads the number of digits in lines and stores in linecCount
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            
            // reads the number of digits in bytes and stores in bytesCount
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            
            // print spaces
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            // print lines
            fprintf(stdout, "%d", lines);
            
            // print spaces
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            
            // print bytes
            fprintf(stdout, "%d\n", bytes);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // else if there are only -l and -c arguments
    else if (!strcmp(argv[1], "-l") && !strcmp(argv[2], "-c")) {
        // read from stdin
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
            
            // reads the number of digits in lines and stores in linecCount
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            // reads the number of digits in lines and stores in linecCount
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            // print spaces
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // print lines
            fprintf(stdout, "%d", lines);
            // print spaces
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // print bytes
            fprintf(stdout, "%d\n", bytes);
            
            fclose(stdin);
            return EXIT_SUCCESS;
        }
    }
    
    // else if -l and file arguments
    else if (!strcmp(argv[1], "-l") && argv[2]) {
        // read from file
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
            
            // reads the number of digits in lines and stores in linecCount
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            // print spaces
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // print lines
            fprintf(stdout, "%d\n", lines);
            
            fclose(file);
            return EXIT_SUCCESS;
        }
    }
    
    // else if -c and file arguments
    else if (!strcmp(argv[1], "-c") && argv[2]) {
        // read file
        file = fopen(argv[2], "r");
        if(file == NULL) {
            fprintf(stderr, "file does not exist\n");
            return EXIT_FAILURE;
        }
        else {
            for (x = getc(file); x != EOF; x = getc(file)) {
                bytes = bytes + 1;
            }

            // reads the number of digits in bytes and stores in byteCount
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            // print spaces
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // print bytes
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
            // reads the number of digits in bytes and stores in bytesCount
            bytesCount = sprintf(bytesArr,"%d", bytes);
            if (bytesCount > 8) {
                fprintf(stderr, "too many bytes in file");
                return EXIT_FAILURE;
            }
            // print spaces
            for(int i = bytesCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // print bytes
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
            
            // reads the number of digits in lines and stores in linecCount
            lineCount = sprintf(linesArr,"%d", lines);
            if (lineCount > 8) {
                fprintf(stderr, "Too many lines in file");
                return EXIT_FAILURE;
            }
            // print spaces
            for(int i = lineCount; i < 8; i++) {
                fprintf(stdout, " ");
            }
            // print lines
            fprintf(stdout, "%d\n", lines);
            
            fclose(stdin);
            return EXIT_SUCCESS;
        }
    }

    // error
    else {
        fprintf(stderr, "an error occured");
        return EXIT_FAILURE;
    }

    
    return 0;
}

