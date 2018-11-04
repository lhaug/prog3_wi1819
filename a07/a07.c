#include <stdio.h>
#include <string.h>

void schreibbit(unsigned int z){
	int i;
	
	for (i=15; i>=0; i--){
			printf("%d", (z & 1<<i) != 0);
	}	
	printf("\n");
}
unsigned int liesbit(void){
	char chars [17];
	int length;	
	int i;
	unsigned int faktor = 1;
	unsigned int erg = 0;
	
	scanf("%s", chars);
	
	length = strlen(chars);
	
	for( i = length-1; i >= 0; i--){
		if ( chars[i] == '1'){
			erg += faktor;
		}
		faktor *= 2;
	}
	
	return erg;
}

int main (void){
	/* test für schreibbit
	 *  
	 * schreibbit(10);
	 * */
	 
	/* test für liesbit
	 * 
		int erg = liesbit();
		
		printf("erg %d \n", erg);
	* */
	
	unsigned int numa, numb, erg1, erg2, erg3;
	
	printf("Zahl 1: ");
	numa = liesbit();
	printf("Zahl 2: ");
	numb = liesbit();
	
	erg1 = numa & numb;
	erg2 = numa | numb;
	erg3 = numa ^ numb;
	
	printf("\n a & b = ");
	schreibbit(erg1);
	printf("\n a | b = ");
	schreibbit(erg2);
	printf("\n a ^ b = ");
	schreibbit(erg3);
	
	
	return 0;
}
