#include <stdio.h>

int main(){
    int sum, pos;
    sum = 0;
    for (pos = 1; pos < 1000; pos++){
        if (pos % 3 == 0 || pos % 5 == 0)
            sum += pos;
    }
    printf("Resultado: %d\n", sum);
    return 0;
}