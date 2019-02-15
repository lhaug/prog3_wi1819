#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct list{
	char data;
	struct list *next;
}list;

list *neuerKnoten(char data){
	list *neu;
	neu = malloc(sizeof(list));
	assert(neu);
	neu->data = data;
	neu->next = NULL;
	return neu;
}

list *insert(list *lis, char data){
	list * neu;
	list *akt;
	
	neu = neuerKnoten(data);
	akt = lis;
	
	if(lis == NULL){
		return neu;
	}else{
		while(akt->next != NULL){
			akt = akt->next;
		}
		akt->next = neu;
		return lis;
	}
}

list *zip(list *lis1, list *lis2){
	list * neue;
	list *lauf1;
	list *lauf2;
	
	neue = NULL;
	lauf1 = lis1;
	lauf2 = lis2;
	
	while((lauf1 != NULL)&&(lauf2 != NULL)){
		neue = insert(neue, lauf1->data);
		neue = insert(neue, lauf2->data);
		lauf1 = lauf1->next;
		lauf2 = lauf2->next;
	}
	while(lauf1 != NULL){
		neue = insert(neue, lauf1->data);
		lauf1 = lauf1->next;
	}
	while(lauf2 != NULL){
		neue = insert(neue, lauf2->data);
		lauf2 = lauf2->next;
	}
	return neue;
}

list *every(list *lis, int offset, int ith){
	int i;
	list *akt;
	list *erg = NULL;
	int lauf = ith;
	
	akt = lis;
	
	for (i=0; i < offset; i++){
		akt = akt->next;
	}
	while(akt!= NULL){
		if(lauf % ith == 0){
			erg = insert(erg, akt->data);
		}
		akt = akt->next;
		lauf++;
	}
	return erg;
}

void printIt(list *lis){
	list *akt = lis;
	while( akt != NULL){
		printf("%c", akt->data);
		akt = akt->next;
	}
	printf("%c", '\n');
}

void freeAll(list *lis){
	list *del = NULL;
	list *akt = lis;
	while( akt != NULL){
		del = akt;
		akt = akt->next;
		free(del);
	}
}

int main (){
	list *lis1 = NULL;
	list *lis2 = NULL;
	list *erg = NULL;
	list *erg2 = NULL;
	
	lis1 = insert(lis1, 'a');
	lis2 = insert(lis2, 'b');
	lis1 = insert(lis1, 'c');
	lis2 = insert(lis2, 'd');
	lis1 = insert(lis1, 'e');
	lis2 = insert(lis2, 'f');
	lis2 = insert(lis2, 'g');
	
	erg = zip(lis1, lis2);
	
	printIt(lis1);
	printIt(lis2);
	printIt(erg);
	
	erg2 = every(erg,2, 2);
	printIt(erg2);
	
	freeAll(lis1);
	freeAll(lis2);
	freeAll(erg);
	freeAll(erg2);

	return 0;
}
