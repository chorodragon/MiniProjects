#include <stdio.h>
#include <math.h>

int main(){
    int sum, mult, aux;
    sum = mult = 0;
    for(aux = 1; aux <= 100; aux++)
        sum += (aux * aux);

    for(aux = 1; aux <= 100; aux++)
        mult += aux;
    mult = mult * mult;

    aux = mult - sum;
    printf("%d\n", aux);
    return 0;
}