#include <stdio.h>
#define MAXLINE 100

void squeeze(char s1[], char s2[]);

int main(){

    int c, cont;
    char s1[MAXLINE], s2[MAXLINE];

    cont = 0;

    while((c = getchar()) != '\n' && c != '\0')
        s1[cont++] = c;
    s1[cont] = '\0';

    cont = 0;
    while((c = getchar()) != '\n' && c != '\0')
        s2[cont++] = c;
    s2[cont] = '\0';

    squeeze(s1, s2);

    fprintf(stdout, "%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[]){
    int c, cont, cont2, pos;

    cont = cont2 = pos = c = 0;
    while(s1[cont] != '\0'){
        while(s2[cont2] != '\0')
            if(s1[cont] == s2[cont2++]){
                c = 1;
                break;
            }
        if(c == 0){
            s1[pos++] = s1[cont];
        }
        cont++;
        cont2 = c = 0;
    }
    s1[pos] = '\0';
}
