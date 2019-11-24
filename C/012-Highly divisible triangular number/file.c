#include <stdio.h>
#include <math.h>

int main(){
    int cont, aux, divisors;
    long num;
    cont = 1;
    num = divisors = 0;

    while(divisors <= 500){
        divisors = 0;
        num += cont;
        for(aux = 1; aux <= sqrt(num); aux++)
            if(num%aux == 0)
                if(aux == sqrt(num))
                    divisors++;
                else
                    divisors += 2;
        cont++;
    }

    printf("%ld\n", num);
    return 0;
}