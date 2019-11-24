#include <stdio.h>
#define OUT 0
#define ONELINE 1
#define MULTILINE 2

int main(){

    int state, c;

    state = OUT;

    while((c = getchar()) != EOF){
        if (state == OUT)
            if(c == '/')
                if((c = getchar()) == '*'){
                    state = MULTILINE;
                    putchar('\n');
                }
                else if(c == '/')
                    state = ONELINE;
                else
                    putchar('/');
        if(state == MULTILINE){
            if(c == '*')
                if((c=getchar()) == '/'){
                    state = OUT;
                    c = getchar();
                }
        }
        else if (state == ONELINE)
            if (c == '\n'){
                state = OUT;
            }
            
        
       if(state == OUT)
          putchar(c); 
    }

    return 0;
}
