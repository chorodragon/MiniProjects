#include <stdio.h>

int main(){
    int c, aux;
    long dec, exp;
    char hexa[30];
    dec = aux = 0;
    exp = 1;
    while((c=getchar()) != '\n' && c != '\0'){
        hexa[aux] = c;
        aux++;
    }

    aux--;
    c = hexa[aux];

    while(aux >= 0 && c != 'x' && c != 'X'){
        if (c > 47 && c < 58)
            c = c - 48;
        else if (c > 64 && c < 71)
            c = c - 55;
        else if(c > 96 && c < 103)
            c = c - 87;
        dec = dec + (c * exp);
        exp = 16 * exp;
        aux--;
        c = hexa[aux];
    }

    printf("Resultado: %d", dec);
    return 0;
}
