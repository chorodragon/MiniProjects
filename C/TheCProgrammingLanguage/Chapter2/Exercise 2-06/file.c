#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(){

    int x, y, p, n; 
    printf("Ingresar x: ");
    scanf("%d", &x);
    printf("Ingresar y: ");
    scanf("%d", &y);
    printf("Ingresar number of bits: ");
    scanf("%d", &n);
    printf("Ingresar position: ");
    scanf("%d", &p);
    printf("Resultado: %d\n", setbits(x, p, n, y));
    return 0;
}

int setbits(int x, int p, int n, int y){
    int var;
    var = y & ~(~0 << n);
    return x | (var << p-n);
}
