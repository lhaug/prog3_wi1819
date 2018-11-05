#include <stdio.h>

char* change(char* aus, char* wird, char* eing){
	
}


int main(int argc, char *argv[]){
	
	char eingabe[100];
	int i;
	char changer;
	char searcher;
	
	char *ausgabe;

	char normal[27]="abcdefghijklmnopqrstuvwxyz";
	char anders[27]="irjmnzltacogdeksvbphxqyuwf";
	
	if(*argv[1] == 'e'){
		ausgabe = change(normal, anders, eingabe);
	}
	if(*argv[1] =='d'){
		ausgabe = change(anders, normal, eingabe);
	}
	
	
	
	while(fgets(eing, sizeof(eing),stdin) != NULL){
		for(i=0; i<100; i++){
			changer = eingabe[i];
			searcher = normal;
			
			if(changer=='\0') break;
			
			while( ){
				
			}
			
			putchar();
		}
	}
	
	
	return 0;
}
