#include <stdio.h>

void change(char* aus, char* wird, char* eing){				
	char *changerpoint;
	char *searcherpoint;
	char *exchangerpoint;
	
	
	changerpoint = eing;
	searcherpoint = aus;
	exchangerpoint = wird;
	
	while(*changerpoint != '\0'){
		while((*searcherpoint != '\0')&&(*searcherpoint != *changerpoint)){
			searcherpoint++;
			exchangerpoint++;
		}
		if(*exchangerpoint == '\0'){
			putchar(*changerpoint);
		}else{
			putchar(*exchangerpoint);
		}
		
		searcherpoint = aus;
		exchangerpoint = wird;
		
		changerpoint ++;
	}
	return;

}


int main(int argc, char *argv[]){
	
	char eingabe[100];
	

	char normal[27]="abcdefghijklmnopqrstuvwxyz";
	char anders[27]="irjmnzltacogdeksvbphxqyuwf";
	
	
	while(fgets(eingabe,100,stdin) != NULL){
		if(*argv[1] == 'e'){
			change(normal, anders, eingabe);
			printf("\n");
		}
		if(*argv[1] =='d'){
			change(anders, normal, eingabe);
			printf("\n");
		}
	}
	
	
	return 0;
}
