#include <stdio.h>
#define TABSTOP 5

int main(){

    int c, cont, aux;
    cont = 0;

    while((c= getchar()) != EOF){
        cont++;
        if (c == '\n')
            cont=0;
        if (c == '\t')
            for(aux = 0; aux <= (cont%TABSTOP); aux++){
                putchar(' ');
                cont++;
            }
        else
            putchar(c);
    }

    return 0;
}
