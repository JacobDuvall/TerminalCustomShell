# cs3113sp19-project0

# Jacob Duvall
Project0 for OS spring '19.

Project0: This project is a custom shell with various commands. The commands run as individual programs. The programs (with examples) are as follows: 

oucat - Takes a series of files or standard input and prints it to standard out.
      - usage: oucat <files>
      - example: ./oucat Makefile

ouecho - Takes text from the command line and prints it to standard out.
       - example: ./ouecho "hello world"

ouhead - Takes file names or standard input and prints the first n lines to standard out.
       - usage: ouhead [-n N] <file>
       - example: ./ouhead -n 6 Makefile

outail - Takes file names or standard input and prints the last n lines to standard out.
       - usage: outail [-n N] <file>
       - example: ./outail -n 6 Makefile

ouseq - Takes one or two integers and prints the integers between these two numbers.
      - usage: ouseq [M] N
      - example: ./ouseq 6 60 

ouwc - Takes files names or standard input and returns the number of lines, words and characters in each file.
     - usage: ouwc [-l | -c] <file>
     - example: ./ouwc -l -c Makefile
      
Helpful web sources I used: 

fgetc(): https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
getc(): https://www.tutorialspoint.com/c_standard_library/c_function_getc.htm
fopen(): https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
fseek(): https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm
fgets(): https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
strcmp(): https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm
sprintf(): https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm

Bugs/Assumptions: 

./oucat assumes that control+C is required to exit the loop when ./oucat is run with no arguments

