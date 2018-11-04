#include <stdio.h>


int main(void){
	int num [20];
	int i, j;
	
	int min, inmin, index, lauf, ende;
	
	min = 0; 
	inmin = 0;
	index = 0;
	lauf = 0;
	
	i = 0;
	j = 0;
	
	while(scanf("%d", &num[i]) != EOF){
		i++;
	}
	
	ende = i;
	
	/* sortieren */
	
	for(index = 0; index < ende; index++){
		min = num[index];
		inmin = index;
		for(lauf = index; lauf < ende; lauf++){
			if(num[lauf] < min){
				inmin = lauf;
				min = num[lauf];
			}
		}
		/* tauschen */
		num[inmin] = num[index];
		num[index] = min;
	}
	
	/* ausgeben*/
	
	for( j = 0; j < ende; j++){
		printf("%6d\n", num[j]);
	}
	
	return 0;
	
}
