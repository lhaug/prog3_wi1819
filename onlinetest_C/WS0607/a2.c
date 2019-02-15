#include <stdlib.h>
#include <stdio.h>

void komprimier(char *dest, const char *src){
	const char *akt = src;
	char *insert = dest;
	char prev = *src;
	int counter = 1;
	akt++;
	
	while(*akt != '\0'){
		if (*akt == prev){
			counter++;
		}else{
			*insert = prev;
			insert++;
			if ((counter > 1)&&(counter < 10)){
				*insert = ((char)counter )+ '0';
				insert++;
			}else if(counter >10 && counter < 100){
				*insert = ((char)(counter/10))+ '0';
				insert++;
				*insert = ((char)(counter%10))+ '0';
				insert++;
			}
			prev = *akt;
			counter = 1;
		}
		akt++;
	}
	*insert = prev;
	insert++;
	if ((counter > 1)&&(counter < 10)){
		*insert = ((char)counter )+ '0';
		insert++;
	}else if(counter >10 && counter < 100){
		*insert = ((char)(counter/10))+ '0';
		insert++;
		*insert = ((char)(counter%10))+ '0';
		insert++;
	}
	*insert = '\0';
}

int main(int argc, char *argv[]){
	int i;
	char dest[200];
	
	for(i=1; i<argc;i++){
		komprimier( dest, argv[i] );
		printf("%s", dest);
		printf("%c", '\n');
	}

	return 0;
}
