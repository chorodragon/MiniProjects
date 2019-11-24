#include <stdio.h>

int main(){

    int sum, temp, first, second;
    sum = 0;
    first = 1;
    second = 2;

    while(second < 4000000){
        if(second % 2 == 0)
            sum += second;
        temp = second;
        second += first;
        first = temp;
    }

    printf("%d\n", sum);

    return 0;
}