/* AUTHOR: JACOB DUVALL
 *
 * DATE: 2/21/19
 *
 * PROGRAM: outail.c
 *
 * DESCRIPTION: Takes file names or standard input and prints the last n lines to standard out.
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

// program to print last n lines from file
int main(int argc, const char * argv[]) {
    
    FILE* file; // file to examine
    char buffer[1000]; // buffer to store character in file
    int totalLines = 0; // number of lines in file
    int i = 0; // i counter
    int lines = 10; // default number is 10
    char usage[27] = "usage: outail [-n N] <file>";
    
    // if nothing given
    if (argc == 1) {
        fprintf(stderr, "%s\n", usage);
        return EXIT_FAILURE;
    }
    
    
    // if no N is given, print last ten lines
    else if (argc == 2) {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "File does not exist\n");
            return EXIT_FAILURE;
        }
        // if file exists
        else {
            // read lines and add them to x; add lines to buffer
            while(fgets(buffer, 1000, file)) {
                totalLines = totalLines + 1;
            }
            // seeks from beginning of file
            fseek(file, i, SEEK_SET);
            // while lines exist in buffer
            while(fgets(buffer, 1000, file)) {
                i = i + 1;
                // if i is greater than the totalLines minus lines wanted, print the buffer line
                if(i > (totalLines - lines)) {
                    fprintf(stdout, "%s", buffer);
                }
            }
            return EXIT_SUCCESS;
        }
        
    }
    
    // if 3 arguments
    else if (argc == 4) {
        // read from file
        file = fopen(argv[3], "r");
        // if file does not exist
        if(file == NULL) {
            fprintf(stderr, "File does not exist\n");
            return EXIT_FAILURE;
        }
        // if file exists
        else {
            // read lines and add them to x; add lines to buffer
            while(fgets(buffer, 1000, file)) {
                totalLines = totalLines + 1;
            }
            // seeks from beginning of file
            fseek(file, i, SEEK_SET);
            // lines are set to number passed in
            lines = atoi(argv[2]);
            // while lines exist in buffer
            while(fgets(buffer, 1000, file)) {
                i = i + 1;
                // if i is greater than the totalLines minus lines wanted, print the buffer line
                if(i > (totalLines - lines)) {
                    fprintf(stdout, "%s", buffer);
                }
            }
            return EXIT_SUCCESS;
        }
    }
    else if (argc == 3) {
        // if file does not exist
        if(stdin == NULL) {
            fprintf(stderr, "File does not exist\n");
            return EXIT_FAILURE;
        }
        // if file exists
        else {
            // read lines and add them to x; add lines to buffer
            while(fgets(buffer, 1000, stdin)) {
                totalLines = totalLines + 1;
            }
            // seeks from beginning of file
            fseek(stdin, i, SEEK_SET);
            // lines are set to number passed in
            lines = atoi(argv[2]);
            // while lines exist in buffer
            while(fgets(buffer, 1000, stdin)) {
                i = i + 1;
                // if i is greater than the totalLines minus lines wanted, print the buffer line
                if(i > (totalLines - lines)) {
                    fprintf(stdout, "%s", buffer);
                }
            }
            return EXIT_SUCCESS;
        }
    }
    
    
    return 0;
}

