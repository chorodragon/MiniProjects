#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    
    printf("Rango de un char %d -> %d\n", CHAR_MIN, CHAR_MAX);
    printf("Rango de un short %d -> %d\n", SHRT_MIN, SHRT_MAX);
    printf("Rango de un int %d -> %d\n", INT_MIN, INT_MAX);
    printf("Rango de un long %ld -> %ld\n", LONG_MIN, LONG_MAX);
    printf("Rango de un signed char %d -> %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Rango de un unsigned char 0 -> %u\n", UCHAR_MAX);
    printf("Rango de un unsigned short 0 -> %d\n", USHRT_MAX);
    printf("Rango de un unsigned int 0 -> %u\n", UINT_MAX);
    printf("Rango de un unsigned long 0 -> %u\n", ULONG_MAX);

    return 0;
}
