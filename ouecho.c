/* AUTHOR: JACOB DUVALL
 *
 * DATE: 2/21/19
 *
 * PROGRAM: ouecho.c
 *
 * DESCRIPTION: Takes text from the command line and prints it to standard out.
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
#include <stdlib.h>

// program that echos the input
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
        fprintf(stderr, "error\n");
        return EXIT_FAILURE;
    }
    return EXIT_FAILURE;
}

