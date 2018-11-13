#include <stdio.h>

#include <ctype.h>

void soundex(const char s[], char res[]){
	char *lookpoint;
	char *insertpoint;
	int length;
	char akt;
	char insert;
	int i;
	
	
	char tabelle[][2] = {'B','1',
						'F','1',
						'P','1',
						'V','1',
						'C','2',
						'G','2',
						'J','2',
						'K','2',
						'Q','2',
						'S','2',
						'X','2',
						'Z','2',
						'D','3',
						'T','3',
						'L','4',
						'M','5',
						'N','5',
						'R','6'};
	/*tabelle[] = "111122222222334556";*/
	
	length = 0;
	
	lookpoint = s;
	insertpoint = res;
	
	
	/*schritt 1*/
	*insertpoint = toupper(*lookpoint);
	length ++;
	lookpoint ++;	
	printf("%s",insertpoint);
	
	/*schritt 2*/
	while(length <= 6){
		
		if(*lookpoint == '\n'){ /* mit Nullen auffülen*/
			insertpoint++;
			*insertpoint = '0';
			length++;
			printf("%s",insertpoint);
			
		}else{
			insert = *insertpoint;
			
			akt = toupper(*lookpoint);
			
			for(i=0; i<19; i++){
				if (akt == tabelle[0][i]){
					insert = tabelle[1][i];
					break;
				}
			}
			
			
			if(insert != *insertpoint){
				insertpoint ++;
				*insertpoint = insert;
				length++;
				printf("%s",insertpoint);
			}
			lookpoint++;
		}
		
		
	}
	insertpoint ++;
	*insertpoint = '\0';
	
	return;
	
}

void ausgabe (char res[]){
	char *point;
	
	point = res;
	
	while(*point != '\0'){
		printf("%s",point);
		point++;
	}
	return;
}

int main (void){
	
	char eingabe[100];
	char res[7];
	
	while(scanf("%s", eingabe) != EOF){
		soundex(eingabe, res);
		/*ausgabe(res);*/
		printf("\n");
	}

	return 0;
}
