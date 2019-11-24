#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100

double atof_(char s[]);
void linea(char s[], int max);

int main(){

    char s[MAXLINE];
    printf("Ingrese un numero: ");
    linea(s, MAXLINE);
    printf("Numero: %f\n", atof_(s));

    return 0;
}

double atof_(char s[]){
    double val, power, exp;
    int i, sign, signp;

    for(i = 0; s[i] == ' '; i++)
        ;
    sign = (s[i] == '-')? -1 : 1;

    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if(s[i] == 'e' || s[i] == 'E')
        i++;
    signp = (s[i] == '-')? -1 : 1;
    
    if (s[i] == '-' || s[i] == '+')
        i++;
    for(exp = 0.0; isdigit(s[i]); i++){
        exp += 10 * exp + (s[i] - '0');
    }
    
    if(signp == 1)
        for(; exp > 0; exp--)
            val *= 10;
    else
        for(; exp > 0; exp--)
            val /= 10;
    return (sign * val / power);
}

void linea(char s[], int max){
    int c, cont;

    cont = 0;
    while((c = getchar()) != '\n' && c != '\0' && cont < max)
        s[cont++] = c;
    s[cont] = '\0';
}
