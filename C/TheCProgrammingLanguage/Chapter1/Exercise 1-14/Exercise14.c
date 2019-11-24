#include <stdio.h>

int main(){
	
	int c;
	int types[4]; //On this array I only took in consideration the blank spaces ' ', the tab '\t', new lines '\n'. All the other symbols (0-9, a-z, specials) are on the same group.


	for(c=0;c<=3;c++){
		types[c] = 0;
	}


	while((c=getchar()) != EOF){
		if(c == ' ')
			types[0]++;
		else if(c == '\n')
			types[1]++;
		else if(c == '\t')
			types[2]++;
		else
			types[3]++;	
		
	}

	printf("Espacios en blanco: ");
	for(c=1; c <= types[0]; c++){
		putchar('|');
	}

	printf("\nNueva linea: ");
	for(c = 1; c <= types[1]; c++){
		putchar('|');
	}

	printf("\nTabulaciones: ");
	for(c=1; c<=types[2]; c++){
		putchar('|');
	}

	printf("\nCaracteres: ");
	for(c=1;c<=types[3];c++){
		putchar('|');
	}

	return 0;
}
