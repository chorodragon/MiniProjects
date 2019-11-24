#include <stdio.h>

int main(){
	
	int i, ant;

	ant = 0;
	
	while((i = getchar())!=EOF){
		if(i == ' '){
			if(i != ant){
				putchar(i);
				ant = i;
			}
			ant = i;
		}
		else{
			putchar(i);
			ant = i;
		}
	}

	return 0;
}
