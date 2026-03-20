#include <stdio.h>
#include <stdbool.h>

int main(int intc, char** args){
    if(intc!=2){ printf("you need different amount of arguments!\n"); return 1; }
    
    FILE* f = fopen("_infile_.0", "w");
    char* c = args[1];
    int index = 0;
    
    while(true){
        char toprint = c[index];
        if(toprint == 0) break;
        switch(toprint){
            case '>': fprintf(f, "0 "); break;
            case '<': fprintf(f, "1 "); break;
            case '+': fprintf(f, "2 "); break;
            case '-': fprintf(f, "3 "); break;
            case '.': fprintf(f, "4 "); break;
            case ',': fprintf(f, "5 "); break;
            case '[': fprintf(f, "6 "); break;
            case ']': fprintf(f, "7 "); break;
        }
        index++;
    }
    
    fclose(f);
    return 0;
}