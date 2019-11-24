#include <stdio.h>

int setbits(int x, int p, int n);

int main(){

    int x, p, n; 
    printf("Ingresar x: ");
    scanf("%d", &x);
    printf("Ingresar number of bits: ");
    scanf("%d", &n);
    printf("Ingresar position: ");
    scanf("%d", &p);
    printf("Resultado: %d\n", setbits(x, p, n));
    return 0;
}

int setbits(int x, int p, int n){
    int var, y, z;
    z = y = x;
    y = y >> p;
    y = y << p;
    z = z << (32 - n);
    z = z >> (32 - n);
    var = x & ~(~0 << p);
    var = var >> (p-n);
    var = var << (p-n);
    var = ~var;
    var = var << (32 - p);
    var = var >> (32 - p);
    var = var >> (p-n);
    var = var << (p-n);
    y = y | var | z;
    return y;
}
