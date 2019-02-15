#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct list{
	char str[30];
	int anz;
	struct list *next;
}list;

list *neuerKnoten(char *str){
	list *neu;
	neu = malloc(sizeof(list));
	assert(neu);
	strcpy(neu->str, str);
	neu->anz = 1;
	neu->next = NULL;
	return neu;
}

list *insert(list *lst, char *str){
	list *neu = neuerKnoten(str);
	list *akt = lst;
	
	if(lst == NULL){
		return neu;
	}else{
		if(akt->next != NULL){
			while(strcmp(akt->next->str, str) < 0){
				if(akt->next->next != NULL){
					akt = akt->next;
				}else{
					akt->next = neu;
					break;
				}			
			}
			if(strcmp(akt->str, str) > 0){
				neu->next = akt;
				return neu;
			}
			neu->next = akt->next;
			akt->next = neu;
		}else{
			akt->next = neu;
		}
	
		return lst;
	}
	
}

void printIt(list *lis){
	list *akt = lis;
	while( akt != NULL){
		printf("%d,%s -- ",akt->anz, akt->str);
		akt = akt->next;
	}
	printf("%c", '\n');
}

int teste(list *lst, char *str){
	list *akt = lst;
	
	while(akt != NULL){
		if(strcmp(akt->str, str) == 0){
			akt->anz = akt->anz+1;
			return 0;
		}
		akt = akt->next;
	}
	return 1;
}

int max(list *lis){
	list *akt = lis;
	int max = 0;
		
	while( akt != NULL){
		if(akt->anz > max){
			max = akt->anz;
		}
		akt = akt->next;
	}
	return max;
}

void printMaxis(list *lst, int x, int max){
	list *maxis[100];
	list **lauf = maxis;
	list *akt = lst;
	char min;
	int leer = 0;
	int i, maxindex;
	
	while(akt != NULL){
		if(akt->anz == max){
			*lauf = akt;
			*lauf++;
			leer++;
		}
		akt = akt->next;
	}
	*lauf = NULL;
	maxindex = leer;
	while(leer != 0){
		/*such min*/
		min = 'z';
		for(i=0; i<maxindex; i++){
			if(maxis[i] != NULL){
				if(*((maxis[i])->str) < min){
					min = *(maxis[i])->str;
				}
			}
		}
				/*printe min und loesche*/

		for(i=0; i<maxindex; i++){
			if(maxis[i] != NULL){
				if(*((maxis[i])->str) == min){
					printf("%d: %s\n",maxis[i]->anz, maxis[i]->str);
					maxis[i] = NULL;
					leer--;
				}
			}
			
		}
		
	}
}

int main (int argc, char *argv[]){
	int i;
	list *lst;
	int maxx;
	
	for (i = 1; i < argc; i++){
		if (teste(lst, argv[i]) == 1){
			lst = insert(lst, argv[i]);
		}
	} 
	printIt(lst);
	maxx = max(lst);
	printMaxis(lst, argc, maxx);
	
	
	return 0;
}
