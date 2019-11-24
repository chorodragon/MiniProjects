#include <stdio.h>
#define MAXLINE 1000

int obtenerlinea(char s[], int lim);
void copy(char to[], char from[]);

int main(){
    int len, max=0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while(len = obtenerlinea(line, MAXLINE))
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max>0)
        printf("Linea mas larga: %s", longest);
    return 0;
}

int obtenerlinea(char s[], int lim){
    int c, i, aux=0;
    for(i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c != EOF && c != '\n'){
        do{
            aux++;
        }while((c=getchar()) != EOF && c != '\n');
    }

    if (c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    i += aux;
    return i;
}

void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
