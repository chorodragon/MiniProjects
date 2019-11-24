#include <stdio.h>

int main(){
    int cont, num, aux, var;
    int primes[10000];
    cont = 0;
    num = 2;
    for (aux = 0; aux < 10000; aux++)
        primes[aux] = 2;
    while(cont < 10000){
        var = 0;
        num++;
        for(aux = 0; aux < 10000; aux++)
            if(num % primes[aux] == 0)
                var = 1;

        if (var == 0)
            primes[++cont] = num;
    }
    printf("Num: %d\n", num);
    return 0;
}