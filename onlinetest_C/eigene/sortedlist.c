#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list* next;
}list;

list * neuerKnoten( int data){
	list * neu;
	neu = malloc(sizeof(list));
	assert(neu);
	neu->data = data;
	neu->next = NULL;
	return neu;
}

void ausgeben(list* lst){
	list *akt = lst;
	while(akt!= NULL){
		printf("%d, ",akt->data);
		akt = akt->next;
	}
	printf("\n");
}

list * insert(list *lst, int data){
	list *akt;
	list * neu = neuerKnoten(data);
	if(lst == NULL){
		return neu;
	}
	akt = lst;
	if(akt->data > data){
		neu->next = akt;
		return neu;
	}
	while(akt->next != NULL){
		if(akt->next->data > data){
			neu->next = akt->next;
			akt->next = neu;
			return lst;
		}
		akt = akt->next;
	}
	if(akt->next == NULL){
		akt->next = neu;
		return lst;
	}
	return lst;
}

int main(){
	
	list *lst=NULL;
	
	lst = insert(lst, 3);
	ausgeben(lst);
	lst = insert(lst, 1);
	ausgeben(lst);
	lst = insert(lst, 7);
	ausgeben(lst);
	lst = insert(lst, 2);
	ausgeben(lst);
	lst = insert(lst, 9);
	ausgeben(lst);
	lst = insert(lst, -1);
	ausgeben(lst);
	
	return 0;
}
