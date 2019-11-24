#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]){

	int c, cont, aux, aux2;
	cont = aux = aux2 = 0;
	c = s[cont++];
	while(c != '\0'){
		c = s[cont++];	
	}
	char cp[cont--];
	aux = --cont;
	cont = 0;
	for(aux; aux >= 0 ; aux--){
		cp[cont++] = s[aux];	
	}
	strcpy(s, cp);
}

void itoa(unsigned n, char s[]){
	int i, sign;

	if((sign = n) < 0)
		n = -n;
	i = 0;

	do{
		s[i++] = n % 10 + '0';
	}while((n /= 10) > 0);
	
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(){
	unsigned x;
	char s[100];

	x = -3215;

	itoa(x, s);
	printf("%s\n", s);
	printf("%d\n", atoi(s));
	return 0;
}
