#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int linea(char s[], int lim);
int strrindex(char s[], char t[]);

int main(){
    int i;
    char s[MAXLINE], t[MAXLINE];

    strcpy(t, "ejemplo");
    while(linea(s, MAXLINE) > 0){
        if((i = strrindex(s, t)) >= 0)
            printf("Posicion: %d\n", i);
        else 
            printf("No encontrando\n");
    }

    return 0;
}

int linea(char s[], int lim){
    int c, i;
    i = 0;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

int strrindex(char s[], char t[]){
    int i, j, k, max;

    max = -1;
    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            max = i;
        
        
    }

    return max;
}
