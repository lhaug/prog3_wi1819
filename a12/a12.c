#include <stdio.h>

#include <string.h>
#include <ctype.h>

void soundex(const char s[], char res[]){
	int i, j, prev;
	char *z[] = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"}, int_char[32];
	
	res[1]='\0';
	
	/*schritt 1*/
	res[0]=toupper(s[0]);
	
	/*schirtt 2*/
	for(i=1; s[i]!='\0';i++){
		for(j=0; j<6; j++){
			if(strchr(*(z+j),toupper(*(s+i))) != NULL && prev != j){
				prev = j;
				sprintf(int_char,"%d", j+1);
				strcat(res, int_char);
			}
		}
	}
	/*mit Nullen auffüllen*/
	for(i=1;i<6;i++){
		if(!res[i]){
			strcat(res,"0");
		}
	}
	/*ausgeben und res leeren*/
	printf("%s\n", res);
	res[0] = '\0';
}

int main (void){
	
	char eingabe[100];
	char res[7];
	
	while(scanf("%s", eingabe) != EOF){
		soundex(eingabe, res);
		printf("\n");
	}

	return 0;
}
