#include <stdio.h>
#include <math.h>
double fmod(double x, double y);
int main(){
    double num, max, fac;

    fac = 2;
    num = 600851475143;
    while (num > 1){
        if(fmod(num, fac) == 0){
            while(fmod(num, fac) == 0)
                num /= fac;
            max = fac;
        }
        fac++;
    }

    printf("%f\n", max);
    return 0;
}