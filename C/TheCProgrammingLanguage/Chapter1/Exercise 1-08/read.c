#include <stdio.h>

int main(){
	
	int i, blank, tab, newlines;
	
	i = blank = tab = newlines = 0;

	while((i = getchar())!=EOF){
		
		if(i == '\t')
			tab++;

		if(i == ' ')
			++blank;

		if(i == '\n')
			newlines++;

		printf("Newlines = %d\tBlanks = %d\tTabs = %d\n%c", newlines, blank, tab, i);
	}

}
