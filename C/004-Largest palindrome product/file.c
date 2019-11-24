#include <stdio.h>
#include <string.h>

int isPal(int num);

int main(){
    int min, max, pal;
    min = 1;
    max = 1;
    while(min < 1000){
        while(max < 1000){
            if(isPal(min * max))
                if((min*max) > pal)
                    pal = min * max;
            max++;
        }
        max = 1;
        min++;
    }
    printf("%d", pal);
    return 0;
}

int isPal(int num){
    char numero[50];
    int cont, aux;
    cont = 0;
    sprintf(numero, "%d", num);
    while(numero[cont] != '\0')
        cont++;
    cont--;
    for(aux = 0; aux < cont; aux++){
        if(numero[aux] != numero[cont])
            return 0;
        cont--;
    }

    return 1;
}