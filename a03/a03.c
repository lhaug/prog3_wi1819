#include <stdio.h>



int main(void){
	int in;
	int laenge= 5;
	char zeichen[6] = {'C','L','X','V','I','\0'};
	int ziffern[5] = {100, 50, 10, 5, 1};
	int divisor;
	char ausg;
	int anzahl = 0;
	int i, j = 0;
	
	while(scanf("%d", &in) != EOF){
		for(i=0; i < laenge; i++){
			divisor = ziffern[i];
			ausg= zeichen[i];
			anzahl= in/divisor;
			in = in%divisor;
			for(j = 0; j < anzahl; j++){
				putchar(ausg);
			}
		}
		printf("\n");
	}	
	return 0;
}
