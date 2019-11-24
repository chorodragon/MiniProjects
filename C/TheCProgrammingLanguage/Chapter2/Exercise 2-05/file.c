#include <stdio.h>
#define MAXLINE 100

int any(char s1[], char s2[]);

int main(){
    int c, aux = 0;
    char s1[MAXLINE], s2[MAXLINE];

    while((c = getchar()) != '\n' && aux < MAXLINE - 1)
        s1[aux++] = c;

    s1[aux] = '\0';
    aux = 0;
    while((c = getchar()) != '\n' && aux < MAXLINE - 1)
        s2[aux++] = c;
    s2[aux] = '\0';
    
    fprintf(stdout, "Occurre en: %d\n", any(s1, s2));
    return 0;
}

int any(char s1[], char s2[]){
    int location, pos, cont;

    location = -1;
    pos = cont = 0;

    while(s1[pos] != '\0' && pos < MAXLINE){
        while(s2[cont] != '\0' && cont < MAXLINE){
            if(s1[pos++] == s2[cont++])
                return pos;
        }
        cont = 0;
    }
    return location;
}
