#include <stdio.h>
#define STEP 20
#define LOW 0
#define MAX 300

float calculate(float val);

int main(){
    for(float fa = LOW; fa <= MAX; fa += STEP){
        printf("Farenheit %.0f Celcius: %.1f\n", fa, calculate(fa));
    }
    return 0;
}

float calculate(float val){
    return ((5.0 / 9.0)*(val-32));
}
