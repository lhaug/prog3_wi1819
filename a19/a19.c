#include <stdio.h>
#include <error.h>

double regula(double x1, double x2, double (*f) (double)){
	double xs;
	int vorzeichenGleich = 0; /*0 = false, 1 = true*/
	double fxs, fx1, betrag;
	
	if(x1 != x2){
		if( f(x1)*f(x2) < 0){
			xs = x1 - f(x1)*(( x2-x1 )/( f(x2)-f(x1) ));
		}
	}else{
		perror("grund");
		/*printf("error");*/
		return 0; /*error*/
	}
	
	fxs = f(xs);
	fx1 = f(x1);
		
	/*weiter suchen*/
	if(fxs < 0 && fx1 < 0){
		vorzeichenGleich = 1;
	}else if(fxs >0 && fx1 >0){
		vorzeichenGleich = 1;
	}else{
		vorzeichenGleich = 0;
	}
	
	/*Nullstelle gefunden*/
	if(fxs < 0 ){
		betrag = fxs * (-1); /*betrag*/
	}else{
		betrag = fxs;
	}
	if(betrag < 1E-6){
		return fxs;
	}
	
	/*weiter suchen - rekursiv*/
	if(vorzeichenGleich == 1){
		return regula(xs, x2, f);
	}else{
		return regula(x1, xs, f);
	}
	
	
}

double f(x){
	return (x*x-9);
}

int main(){
	double x1, x2, erg;
	
	x1 = -2;
	x2 = 2;
	erg = regula(x1, x2, f);
	printf("%d",erg);
	
	return 0;
}
