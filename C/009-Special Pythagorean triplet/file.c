#include <stdio.h>

int main(){

    int a, b, c, total;
    c = 3;
    total = 1000;

    while(c < total){
        b = 2;
        while(b < c){
            a = 1;
            while(a < b){
                if((a+b+c) == 1000){
                    if((a*a + b*b) == (c*c))
                        printf("A: %d, B: %d, C: %d - Result: %d\n", a, b, c, (a*b*c));
                }
                a++;
            }
            b++;
        }
        c++;
    }

    return 0;
}