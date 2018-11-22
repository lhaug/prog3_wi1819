#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
	void *data2;
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct Node *nodep;

nodep neuerKnoten (void){
	nodep p;
	
	p = malloc(sizeof(struct Node));
	assert(p);
	p->next = NULL;
	p->prev = NULL;
	p->data2 = NULL;
	p->data = 0;
	
	return p;
}

void printList(nodep lst){
	nodep akt = lst;
	while(akt != NULL){
		printf("%d\n",(int)(akt->data));
		akt = akt->next;
	}
}

nodep insertAt(nodep lst, int pos, void *data2, int data){
	
	nodep neu = neuerKnoten();
	nodep akt = lst;
	int i;
	neu->data = data;
	
	if(pos == 0){
		if(lst == NULL){
			lst = neu;
		}else{
			neu->next = akt;
			akt->prev = neu;
		}
	}else if(pos < 0){
		while(akt->next != NULL){
			akt = akt->next;
		}
		akt->next = neu;
		neu->prev = akt;
	}else if(pos > 0){
		for(i=1; i < pos; i++){
			if(akt->next != NULL){
				akt = akt->next;
			}
		}
		neu->next = akt->next;
		neu->prev = akt;
		akt->next = neu;
	}
	return lst;
}

nodep deleteAt(nodep lst, int pos){
	int i;
	nodep akt=lst;
	nodep del;
	
	if(lst == NULL) return NULL;
	
	if(pos==0){
		del = lst;
		lst = lst->next;
		free(del);
	}else{
		for(i=0;i<pos;i++){
			if(akt->next != NULL){
				akt = akt->next;
			}
		}
		del = akt;
		del->prev->next = akt->next;
		akt->next->prev = del->prev;
		free(del);
	}
	
	return lst;
}

void deleteList(nodep lst){
	nodep akt=lst;
	nodep del;
	
	while(akt!= NULL){
		del = akt;
		akt = akt->next;
		free(del);
	}
	
	return;	
}
nodep copyList(nodep lst){
	nodep akt;
	nodep newlst;
	
	/*ans ende der Liste 1*/
	while(akt->next != NULL){
		akt = akt->next;
	}
	/*von hinten nach vorne Elemente "kopieren" immer vorne 
	 * in der neuen Liste einfügen*/
	while(akt != NULL){
		newlst = insertAt(newlst, 0, akt->data2, akt->data);
		akt = akt->prev;		
	}
	
	return newlst;
}

int main(){
	int *A, *B, *C,a,b,c;
	nodep testlst;
	nodep newlist;
	
	a = 1;
	b = 2;
	c = 3;
	
	A = &a;
	B = &b;
	C = &c;
	testlst = NULL;
	
	printf("A=%d B=%d C=%d\n", *A,*B, *C);
	testlst = insertAt(testlst, 0, A, a);
	testlst = insertAt(testlst, 1, C, c);
	testlst = insertAt(testlst, 1, B, b);
	printf("liste 1\n");
	printList(testlst);
	newlist = copyList(testlst);
	printf("liste 2\n");
	printList(newlist);
	testlst = deleteAt(testlst, 1);	
	printf("liste 1\n");
	printList(testlst);
	printf("liste 2\n");
	printList(newlist);
	deleteList(testlst);
	
	return 0;
}
