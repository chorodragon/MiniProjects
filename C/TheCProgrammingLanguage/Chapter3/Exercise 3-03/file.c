#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main(){
    
    char s1[MAXLINE], s2[MAXLINE];

    strcpy(s1, "A-Za-z0-9");
    expand(s1, s2);
    printf("%s\n", s2);

    strcpy(s1, "-a-z");
    expand(s1, s2);
    printf("%s\n", s2);

    strcpy(s1, "a-z0-9");
    expand(s1, s2);
    printf("%s\n", s2);

    strcpy(s1, "A-Z");
    expand(s1, s2);
    printf("%s\n", s2);


    return 0;
}

void expand(char s1[], char s2[]){
    int c, n, pos, aux;
    n = pos = 0;
    c = s1[n++];
    
    while(c != '\0'){
        if(c == '-'){
            s2[pos++] = c;
        }

        else if(c == 'A'){
            if((c = s1[n++]) == '-'){
                if ((c = s1[n++]) == 'Z'){
                    for(aux = 'A'; aux <= 'Z'; aux++)
                        s2[pos++] = aux;
                }
            }
        }

        else if(c == 'a'){
            if((c = s1[n++]) == '-'){
                if ((c = s1[n++]) == 'z'){
                    for(aux = 'a'; aux <= 'z'; aux++)
                        s2[pos++] = aux;
                }
            }
        }
    
        else if(c == '0'){
            if((c = s1[n++]) == '-'){
                if((c = s1[n++]) == '9'){
                    for(aux = '0'; aux <= '9'; aux++)
                        s2[pos++] = aux;
                }
            }
        }
        else{
            putchar(c);
        }
        c = s1[n++];
    }
    s2[pos] = '\0';
}
