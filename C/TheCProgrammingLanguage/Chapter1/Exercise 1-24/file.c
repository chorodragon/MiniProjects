#include <stdio.h>
#define ONELINE 1
#define MULTILINE 2
#define QUOTE 3
#define DOUBLEQUOTE 4
#define OUT 0

int main(){


    int state, linea, paren, corch, llaves, c;

    state = OUT;
    linea = paren = corch = llaves = 0;

    while((c=getchar()) != EOF){
        if (state == OUT){
            if(c == '(')
                ++paren;
            else if(c == '[')
                ++corch;
            else if(c == '{')
                ++llaves;
            else if(c == ')')
                --paren;
            else if(c == '}')
                --llaves;
            else if(c == ']')
                --corch;
            else if(c == '"')
                state = DOUBLEQUOTE;
            else if(c == '\'')
                state = QUOTE;
            else if(c == '/'){
                if ((c = getchar()) == '/')
                    state = ONELINE;
                else if (c == '*')
                    state = MULTILINE;
            }
            if (c == '\n'){
                if (paren != 0 || corch != 0)
                    fprintf(stderr, "Error en la linea %d\n", linea);
                ++linea;
                llaves = 0;
                corch = 0;
            }
        }
        else if (state == ONELINE){
            while(c != '\n' || c != EOF)
                c = getchar();
            state = OUT;
            linea++;
        }
        else if (state == MULTILINE){
           while((c = getchar()) != EOF){
                if (c == '*')
                    if((c = getchar()) == '/'){
                        state = OUT;
                        break;
                    }
                if (c == '\n')
                    linea++;
           } 
        }
        else if (state == QUOTE){
            while(c != EOF){
                if((c = getchar()) == '\''){
                    state = OUT;
                    break;
                }
                if(c == '\n')
                    linea++;
            }
        }
        else if (state == DOUBLEQUOTE){
             while(c != EOF){
                if((c = getchar()) == '"'){
                    state = OUT;
                    break;
                }
                if(c == '\n')
                    linea++;
             }
        }
    }

    if(llaves != 0)
        fprintf(stderr, "Error con la cantidad de llaves.\n");

    return 0;
}
