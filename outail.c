#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    FILE* file;
    file = fopen(argv[3], "r");
    char buffer[1000];
    int x = 0;
    int i = 0;
    int lines = 10; // default number is 10
    char z;

    for (z = getc(file); z != EOF; z = getc(file)) {
        x = x+1;
    }
    
    fseek(file, i, SEEK_SET);
    
    lines = atoi(argv[2]);
    
    while(fgets(buffer, 1000, file))
    {
        i = i + 1;
        if(i > x - lines)
            fprintf(stdout, "%s", buffer);
    }
    return 0;
}

