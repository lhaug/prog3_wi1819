#include <string.h>
#include <stdio.h>

int rem_double(char *s){
	char prev;
	char *akt;
	char *einf;
	
	einf = s;
	prev = '\0';
	akt = s;
	while(*akt != '\0'){
		if(*akt != prev){
			prev = *akt;
			*einf = *akt;
			einf++;
		}
		akt ++;
	}
	*einf = '\0';
	
	return 0;
}

int rem_double_sel(const char *s, char *sel){
	return 0;
}

int main(){
	char s1[] = "Halllllooooo Weeeltttt";
	rem_double(s1);
	
	printf("%s", s1);
	return 0;
}
