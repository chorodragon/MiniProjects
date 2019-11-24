#include <stdio.h>

int main(){
    
    int i, c, lim = 10;
    char s[lim];

    for(i = 0; i < lim-1; i++){
        c = getchar();
        if(c == '\n')
            break;
        else if(c == EOF)
            break;
        s[i] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}
