#include <stdio.h>

#define In 1
#define Out 2

int main(){
	
	int c, state;
	
	state = Out;

	while((c=getchar()) != EOF){
		
		if(c == ' '){
			putchar('\n');
		}
		else{
			putchar(c);
		}
		
	}

	return 0;
}
