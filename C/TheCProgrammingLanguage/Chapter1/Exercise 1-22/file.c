#include <stdio.h>
#define MARGIN 20
#define MAXPALABRA 100

void obtenerpalabra(char palabra[], int *cont);

int main(){

    int *cont, real;
    char palabra[MAXPALABRA];
    real = 0;
    cont = &real;

    obtenerpalabra(palabra, cont);
    while(palabra[0] != EOF){
        if (real >= MARGIN){
            putchar('\n');
            printf("%s", palabra);
            real = real - 20;
        }
        else
            printf("%s", palabra);
        obtenerpalabra(palabra, cont);
    }

    return 0;
}

void obtenerpalabra(char palabra[], int *cont){
    int c, aux;

    for (aux = 0; aux < MAXPALABRA-1 && (c=getchar()) != '\n' && c != ' ' && c != EOF; aux++){
        palabra[aux] = c;
        *cont += 1;
    }
    if(c == '\n' || c == ' '){
        palabra[aux] = c;
        aux++;
    }
    if(c == '\n')
        *cont = 0;
    palabra[aux]='\0';

    if(c == EOF)
        palabra[0] = c;
}
