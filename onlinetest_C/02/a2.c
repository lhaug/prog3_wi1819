#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	char data;
	struct list *next;
}list;

list *neuerKnoten(char data){
	list *new;
	new = malloc(sizeof(list));
	assert(new);
	new->data = data;
	new->next = NULL;
	return new;
}

list *insert(list *lis, char data){
	list *n;
	list *akt;
	akt = lis;
	n = neuerKnoten(data);
	if ( lis == NULL ){
		return n;
	}else{
		while(akt->next != NULL){
			akt = akt->next;
		}
		akt->next = n;
		return lis;
	}
}

list * rotate_left(list *lis){
	list *akt;
	list *old;
	
	akt = lis;
	if(akt->next == NULL){
		return lis;
	}
	if( akt != NULL ){
		old = akt;
		lis = akt->next;
		while(akt->next != NULL){
			akt = akt->next;
		}
		akt->next = old;
		old->next = NULL;
	}
	return lis;
}

list *rotate_right(list *lis){
	list *last;
	list *prev;
	
	if(lis->next == NULL){
		return lis;
	}
	last = lis;
	prev = lis;
	while(last->next != NULL){
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = lis;
	lis = last;
	return lis;
}

void printlist(list *lis){
	list * akt = lis;
	while(akt != NULL){
		printf("%c",akt->data);
		akt = akt->next;
	}
	printf("%c",'\n');
}

void freeAll(list * lis){
	list *akt = lis;
	list* del;
	while(akt != NULL){
		del = akt;
		akt = akt->next;
		free(del);
	}
}

int main(){
	list *mylist = NULL;
	mylist = insert(mylist, 'a');
	
	mylist = rotate_left(mylist);
	
	printlist(mylist);
	mylist = rotate_right(mylist);
	printlist(mylist);
	mylist = rotate_right(mylist);
	printlist(mylist);
	
	freeAll(mylist);
	
	return 0;
}
