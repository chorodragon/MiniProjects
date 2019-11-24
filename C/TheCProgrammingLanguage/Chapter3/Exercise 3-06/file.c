#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int w){
	int i, aux, mult;
	i = 0;
    s[i++] = '0';
	do{
        aux = 1;
        while((n / aux) > 15)
            aux *= 16;
        mult = aux;
        aux = n / aux;
        switch(aux){
            case 1: s[i++] = '1'; break;
            case 2: s[i++] = '2'; break;
            case 3: s[i++] = '3'; break;
            case 4: s[i++] = '4'; break;
            case 5: s[i++] = '5'; break;
            case 6: s[i++] = '6'; break;
            case 7: s[i++] = '7'; break;
            case 8: s[i++] = '8'; break;
            case 9: s[i++] = '9'; break;
            case 10: s[i++] = 'A'; break;
            case 11: s[i++] = 'B'; break;
            case 12: s[i++] = 'C'; break;
            case 13: s[i++] = 'D'; break;
            case 14: s[i++] = 'E'; break;
            case 15: s[i++] = 'F'; break;
        }
	}while((n -= aux * mult ) > 0);
	s[i] = '\0';
	if(i < w){
        char blank[w-i];
        
        for(aux = 0; aux <= (w-i); aux++){
            blank[aux] = ' ';
        }
        strcpy(s, strcat(blank, s));
    }
}

int main(){
	int x, w;
	char s[100];

    printf("Ingrese un numero: ");
    scanf("%d", &x);

    printf("Ingrese el ancho: ");
    scanf("%d", &w);


	itob(x, s, w);
	printf("%s\n", s);
	return 0;
}
