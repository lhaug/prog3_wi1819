#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "textfun.h"

ListEle *wordList = NULL;

ListEle *neuerKnoten(const char *such, const char*ersatz){
	ListEle *neu;
	neu = malloc(sizeof(struct listEle));
	assert(neu);
	strcpy(neu->suchwort, such);
	strcpy(neu->ersatzwort, ersatz);
	neu->next = NULL;
	return neu;
}

void addPair(const char *such, const char *ersatz){
	ListEle *akt = wordList;
	ListEle *neu = neuerKnoten(such, ersatz);
	
	if(wordList == NULL){
		wordList = neu;
	}else{
		while(akt->next != NULL){
			akt = akt->next;
		}
		akt->next = neu;
	}
}

void clearList(void){
	ListEle *akt = wordList;
	ListEle *del = akt->next;
	
	while(del != NULL){ /*löschen aller Eles nach head, immer 2.Stelle*/
		akt->next = del->next;
		free(del);
		del = akt->next;
	}
	/*löschen des letzten Elements*/
	del = wordList;
	wordList = NULL;
	free(del);
}

Fundstelle *neueFundstelle(){
	Fundstelle *neu;
	neu = malloc(sizeof(Fundstelle));
	assert(neu);
	neu->stelleImSuchstring = NULL;
	neu->ersetzung=NULL;
	return neu;
}

Fundstelle *find(const char *s){
	int i;
	int true;
	const char *try;
	char *try2;
	const char *akt = s;
	ListEle *ele;
	Fundstelle *found;
	
	while(akt != '\0'){
		ele=wordList;
		while(ele != NULL){
			if(*akt==*(ele->suchwort)){/*erster Buchstabe ist identisch*/
				try = akt;
				try2 = ele->suchwort;
				true = 0;
				for(i=0; i < strlen(ele->suchwort); i++){/*ist es wirklich das wort?*/
					if(*try != *try2){
						true = 1;
						break;
					}else{
						try++;
						try2++;
					}
				}
				if(true == 0){ /*es war das wort*/
					found = neueFundstelle();
					strcpy(found->stelleImSuchstring, akt);
					found->ersetzung = ele;
					
					return found;
				}
			}
			ele=ele->next;
		}
		akt++;
	}
	return NULL;	
}

int replaceAll(char *s){
	char *akt = s;
	char *akt2;
	char tempo;
	char *temp;
	Fundstelle *found;
	int changes = 0;
	temp = &tempo;
	
	
	while(*akt != '\0'){
		found = find(akt);
		if(found == NULL) return changes;
		/*tauschen*/
		akt = found->stelleImSuchstring;
		/*rest in temp kopieren*/
		akt2 = (found->stelleImSuchstring)+strlen((found->ersetzung)->suchwort);
		strcpy(temp, akt2);
		/*ersatzwort einfügen*/
		strcpy(akt, (found->ersetzung)->ersatzwort);
		/*Rest wieder hinten dran*/
		akt = akt + strlen((found->ersetzung)->ersatzwort);
		strcpy(akt, temp);		
	}
	
	return 0;
}
