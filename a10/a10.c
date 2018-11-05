#include <stdio.h>

int main(void){
	char *a = NULL;
	int *b = NULL, v[17];
	double *c = NULL;
	
	printf("\n%ld %ld %ld\n%ld %ld %ld\n\n",
			(long) (a+1), (long) (b+1), (long) (c+1), /*ADRESSEN NULL um 1 char verschoben (1bit), um 1 int verschoben (4bit), um ein double verschoben (8bit)*/
			(long) (a+5), (long) (b+7), (long) (c+17)); /*um n*x verschoben*/
	
	printf("%p %p %p\n", (void*)v, (void*)&v[0], (void*)&v[10]); 
	/*voidZeiger damit %p diesen als hexadezimal ausgeben kann
	 * 
	 * 1. und 2. identisch (Adresse in hexadezimal)
	 * 3. Adresse von 11. Wert, also Adresse + 40 (10*4bit(int))
	 * */

	return 0;
}
