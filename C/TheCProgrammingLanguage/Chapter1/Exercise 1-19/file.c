#include <stdio.h>
#define MAXSTRING 1000

int obtener(char linea[]);
void invertir(char linea[], char invertida[]);

int main(){

    int c;
    char linea[MAXSTRING], invertida[MAXSTRING];

    while (obtener(linea)){
        invertir(linea, invertida);
        printf("%s\n", invertida);
    }

    return 0;
}

int obtener(char linea[]){
    int c, car;
    car = getchar();
    for(c = 0; c < MAXSTRING-1 && car != '\n' && car != EOF; c++){
        linea[c] = car;
        car = getchar();
    }
    if(car == EOF)
        return 0;
    else{
        linea[c] = '\0';
        return 1;
    }
}

void invertir (char linea[], char invertida[]){
    int aux, largo=0, inv;
    aux = linea[largo];
    while(aux != '\0'){
        largo++;
        aux = linea[largo];
    }
    inv = largo-1;
    for(aux=0; aux < largo; aux++){
        invertida[aux] = linea[inv];
        inv--;
    }
    invertida[aux] = '\0';
}
