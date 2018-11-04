#include <stdio.h>

int correctx(int x, int maxindex){
	if( x < 0){
		x = maxindex;
	}
	if( x > maxindex){
		x = x % (maxindex+1);
	}	
	
	return x;
}
int correcty( int y, int maxindex){
	if( y < 0){
		y = y * (-1);
	}
	if( y > maxindex){
		y = y % (maxindex+1);
	}
	
	return y;
}

int main (void){
	int n;
	int quadrat [100][100];
	int i, j, k;
	int aktx, akty;
	int newx, newy;
	int maxindex;
	
	quadrat[0][0] = 0;
	aktx = 0; 
	akty = 0;
	newx= 0;
	newy = 0;
	
	scanf("%d", &n);
	
	if( (n%2) == 0 ){
		printf("Fehleingabe");
		return 1;
	}
	
	maxindex = n-1;
	
	for(i=1; i <= (n*n); i++){
		if( i == 1){
			aktx = maxindex/2; /*mitte, ganzzahl division*/
			akty = maxindex/2; /*mitte, ganzzahl division*/
		
		}else{
			
			/*links drunter*/
			newx = correctx( (aktx - 1), maxindex);
			newy = correcty( (akty + 1), maxindex);
			
						
			/*ist das Feld schon belegt?*/
			if(quadrat[newx][newy] != 0){
				
				/*2 drunter*/
				newx = aktx;
				newy = correcty( (akty +2),maxindex);
			}
			
			aktx = newx;
			akty = newy;
			
		}
		newx = 0;
		newy = 0;	
		quadrat[aktx][akty]=i;	
	}
	
	/*ausgabe*/
		
	for(j=0; j<n; j++){
		for(k=0; k<n; k++){
			printf(" %3d ",quadrat[k][j]);
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
