#include <stdio.h>

int main(){

	int c, tam=0;

	while((c=getchar()) != EOF){
		if(c != ' ' && c != '\n' && c != '\t'){
			tam++;
		}
		else{
			if(tam != 0){
				for(c = 1; c <= tam; c++){
					putchar('-');
					putchar('\n');
				}
				tam = 0;
				putchar('\n');
			}
		}

	}

	return 0;
}
