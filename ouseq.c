/* AUTHOR: JACOB DUVALL
 *
 * DATE: 2/21/19
 *
 * PROGRAM: ouseq.c
 *
 * DESCRIPTION: Takes one or two integers and prints the integers between these two numbers.
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
#include <unistd.h>

// program to print numbers in increasing, decreasing, or equal order
int main(int argc, const char * argv[]) {
    
    int number1 = 0; // number holder one
    int number2 = 0; // number holder two
    char *usage = "usage: ouseq [M] N"; // usage statement
    
    // print usage statement
    if (!strcmp(argv[1], "-h")) {
        fprintf(stdout,"%s\n", usage);
        return EXIT_SUCCESS;
    }
    
    // if no numbers
    if(!argv[1]) {
        return EXIT_FAILURE;
    }
    
    // if argv[1] exist assign to number1
    if(argv[1]) {
        number1 = atoi(argv[1]);
    }
    // if argv[2] exist assign to number2
    if(argv[2]) {
        number2 = atoi(argv[2]);
    }
    
    // if no number 2 print from 0 to number1
    if(!argv[2]) {
        for(int i = 0; i <= number1; i++) {
            fprintf(stdout, "%d\n", i);
        }
        return EXIT_SUCCESS;
    }
    
    // if number1 less than number2 print from number1 to number2
    else if(number1 < number2) {
        for(int i = number1; i <= number2; i++) {
            fprintf(stdout, "%d\n", i);
        }
        return EXIT_SUCCESS;
    }
    
    // if number1 greater than number2 print from number1 to number2
    else if(number1 > number2) {
        for(int i = number1; i >= number2; i--) {
            fprintf(stdout, "%d\n", i);
        }
        return EXIT_SUCCESS;
    }
    
    // if number1 equals number2 print number1
    else if(number1 == number2) {
        fprintf(stdout,"%d\n", number1);
        return EXIT_SUCCESS;
    }
    
    // error
    fprintf(stderr, "%s\n", usage);
    return EXIT_FAILURE;

}

