#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
	char *in[30];
	int *number;
	double eingabe;
	
	number = malloc(sizeof(double));
	
	scanf("%s", in);
	
	sscanf(in, "%lf", &eingabe);
	
	*number = eingabe;
	
	printf("%d",number);
	
}
