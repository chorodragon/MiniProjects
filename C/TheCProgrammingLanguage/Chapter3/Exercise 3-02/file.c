#include <stdio.h>
#define MAXLINE 1000

void escape(char t[], char s[]);

int main(){
    
    char s[MAXLINE], t[MAXLINE];
    int c, cont;

    c = cont =  0;
    printf("Ingrese el primer string:\n");
    while(c != '\n' && cont < MAXLINE-1){
        c = getchar();
        t[cont++] = c;
    }
    t[cont] = '\0';
    
    escape(t, s);

    printf("%s\n", s);

    return 0;
}

void escape(char t[], char s[]){
    int poso, posc;
    poso = posc = 0;

    while(t[poso] != '\0'){
        switch(t[poso]){
            case '\n': 
                s[posc++] = '\\';
                s[posc++] = 'n';
                break;
            case '\t': 
                s[posc++] = '\\';
                s[posc++] = 't';
                break;
            case ' ': break;

            default: s[posc++] = t[poso];
        }
        poso++;
    }
    s[poso] = '\0';
}
