#include <stdio.h>
#include "textfun.c"

int main(int argc, char *argv[]){
	
	char text[201];
	int anzahl;
	const char *such={"suchwort"};
	const char *ersatz={"ersetzungswort"};
	int i = 0;
	
	while( i < argc){
		/*aus argv suchwort=ersatzwort adden*/
		addPair(such, ersatz);
	}	
	
	while( scanf("%s", text) != EOF){
		
		anzahl=replaceALL(text);
		printf("%s"" ", text);
		
	}
	
	return 0;
}
