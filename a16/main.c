#include <stdio.h>
#include <string.h>
#include "textfun.h"

int main(int argc, char *argv[]){
	
	char text[201];
	int anzahl;
	char such[30];
	char *ersatz;
	char *akt;
	int i;
	int j;
	
	for(i=1; i < argc; i++){
		j = 0;
		akt=argv[i];
		while(*akt != '='){
			such[j]=*akt;
			j++;
			akt++;
		}
		such[j]='\0';
		akt++;
		ersatz=akt;
		
		addPair(such, ersatz);
	}
	
	while( scanf("%s", text) != EOF){
		
		anzahl=replaceAll(text);
		printf("Anzahl: %d - %s", anzahl, text);
		
	}
	
	clearList();
	
	return 0;
}
