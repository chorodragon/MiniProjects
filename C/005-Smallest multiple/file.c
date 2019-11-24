#include <stdio.h>

int main(){
    int num, aux, mult;
    mult = 10;
    do{
        aux = 0;
        mult++;
        for(num = 1; num <= 20; num++){
            if((mult % num) != 0){
                aux = 1;
                break;
            }
        }
    }while(aux != 0);

    printf("%d\n", mult);
    return 0;
}