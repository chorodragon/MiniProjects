#include <stdio.h>
#define TABSTOP 4

int main(){

    int c, cont, blank, aux;

    cont = 0;
    while((c=getchar()) != EOF){
        cont++;
        blank = 0;
        aux = 0;
        if(c == ' '){
            while((c = getchar()) == ' '){
                blank++;
                aux++;
            }
            blank++; 
            cont++;
        }
        if ((cont%TABSTOP) < blank && aux > 0)
            blank = cont%TABSTOP;
        for(int aux = 0; aux < blank; aux++)
            putchar(' ');
        putchar(c);
    }

    return 0;
}
