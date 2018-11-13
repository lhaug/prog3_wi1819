#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	char name[25];
	struct Person *next;
}person;

int einfuegen(char name[], struct Person *akt){
	struct Person *pers;
	pers = malloc(sizeof(struct Person));
	if(!pers) return 1; /*malloc fehler- Ende*/
	
	strcpy(pers->name,name);
	
	if (akt == 0){
		akt = pers;
	}else{
		akt->next = pers;
	}
	return 0;
}

void loeschen(struct Person *del){
	free(del);
	return;
}


int main (int argc, char *argv[]){
		
	struct Person *anfang;
	struct Person *akt = 0;
	char name[25];
	
	while(scanf("%s", name) != EOF){
		einfuegen(name, akt);
		printf("%s\n", akt->name);
	}
	
	return 0;
}
