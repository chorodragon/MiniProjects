#include <stdio.h>
#define LENGHT 80
#define MAXIMO 1000

int obtenerlinea(char linea[], int max);

int main(){
    char linea[MAXIMO];
    int var;

    while(var = obtenerlinea(linea, MAXIMO))
        if(var > LENGHT)        
            printf("%s", linea);

    return 0;
}

int obtenerlinea(char linea[], int max){
    int largo, aux, var;
    
    for(largo = 0; (aux = getchar()) != EOF && aux != '\n'; largo++)
        if(largo < max-1){
            linea[largo] = aux;
            var = largo;
        }
    if(largo < max)
        var = largo;
    else
        var++;

    if (aux == '\n'){
        linea[var] = aux;
        var++;
    }
    linea[var]='\0';
    return largo;
}
