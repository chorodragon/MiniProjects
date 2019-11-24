#include <stdio.h>

int count(unsigned int x);

int main(){
    unsigned int x;

    printf("Ingrese x: ");
    scanf("%u", &x);

    printf("Total: %d\n", count(x));

    return 0;
}

int count(unsigned int x){
    int result=1;

    while(x != 0){
        if(x &= x-1)
            result++;
    }

    return result;
}
