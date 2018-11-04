#include <stdio.h>

double wurzelrechner(double w, int x){
	return (w+(x/w))/2;
}

double abstand(double w1, double w2){
	double w;
	w = w1 - w2;
	if ( w < 0){
		return w*(-1);
	}else{
		return w;
	}
	
}

int main (void){
	
	int x;
	double w;
	double w2;
	
	while(scanf("%d", &x) != EOF){
		if (x == 0){
			return 1;
		}else{
			w = (1+x)/2;
			w2 = wurzelrechner(w,x);
			while( abstand(w, w2) > 10e-7){
				w = w2;
				w2 = wurzelrechner(w,x);
			}
			printf("%f \n",w2);
		}
	}
	return 0;
} 
