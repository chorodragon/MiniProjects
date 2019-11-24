#include <stdio.h>

int main(){
    int c;
    while((c = getchar()) != '\0')
	putchar(lower(c));
    return 0;
}

int lower(int c){
	return c >= 'A' && c <= 'Z'? c +'a' - 'A': c;	
}
