#include <stdio.h>
#include <math.h>

int isPrime(int valor);

int main(){
    int valor, cien;
    double suma;
    suma = 17;
    cien = 100000;
    for (valor = 10; valor < 2000000; valor++){
        if(isPrime(valor))
            suma += valor;
        if(valor == cien ){
            printf("Suma %f - Valor: %d\n", suma, valor);
            cien += 100000;
        }
    }

    printf("%f\n", suma);
    return 0;
}

int isPrime(int valor){
    int cont;
    for(cont = 2; cont <= sqrt(valor); cont++)
        if(valor%cont == 0)
            return 0;
    return 1;
}