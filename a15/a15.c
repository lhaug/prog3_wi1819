#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
	
	char text[201];
	char *bad;
	int length;
	int i = 1;
	int j;
	
	while(fgets(text,200,stdin) != NULL){
		while(i < argc){/*ende von argv*/
			/*char *strstr(sonst char *haystack, const char *needle)
			 * 
			 * strstr finds the first occurence of 
			 * the substring needle in the string haystack ('\0' wird nicht verglichen)*/
			bad = strstr(text, argv[i]);
			length = strlen(argv[i]);
			/*length = sizeof(argv[i])/sizeof(char); falsche Berechnung*/
			
			while(bad != NULL){
				bad ++;/*erster Buchstabe bleibt stehen*/
				for(j=1; j < length; j++){/*rausstreichen mit * */
					*bad = '*';
					bad++;
				}
				bad = strstr(text, argv[i]);
			}
			i++;
		}
		
		printf("%s\n", text);
	}
		
	return 0;	
}
