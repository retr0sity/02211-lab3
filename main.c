#include <stdio.h>
#include <stdbool.h>

int main(int intc, char** args){
    if(intc!=2){ printf("you need different amount of arguments!\n");}
    char * c=args[1];
    int index=0;
    printf("{");
    while(true){
        char toprint=c[index];
        if(toprint==0){break;}

        switch (toprint) {
            case '>':
                printf("0");
                break;
            case '<':
                printf("1");
                break;
            case '+':
                printf("2");
                break;
            case '-':
                    printf("3");
                    break;
            case '.':
                    printf("4");
                    break;
            case ',': 
                    printf("5");
                    break;
            case '[':
                    printf("6");
                    break;
            case ']':
                    printf("7");
                    break;
            default:
        printf("Default case is Matched.");
        break;
        
            }
        printf(",");
        index++;
    }
    printf("}\n");
    


    return 0;
}