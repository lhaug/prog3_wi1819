#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Person{
	char name[25];
	struct Person *next;
}Person;

Person *neuerKnoten(void){
	Person *p;
	
	p = malloc(sizeof(struct Person));
	assert(p);
	p->name[0] = '\0';
	p->next = NULL;
	
	return p;
}

Person* einfuegen(char *newname, Person *anfang){
	Person *pers = anfang;
	
	if(anfang == (Person*)NULL){
		anfang = neuerKnoten();
		anfang->next = anfang; /*weil kreis*/
		strcpy(anfang->name, newname);
	}else{
		while(pers->next != anfang){
			pers = pers->next;
		} 	
		pers->next = neuerKnoten();
		pers = pers->next;
		pers->next = anfang;
		strcpy(pers->name, newname);
	}
	
	return anfang;
}

void loeschen(Person *del){
	free(del);
	return;
}

Person* abzaehlen(Person *anfang, int count){
	
	/*warum geht das ohne dass aktPers oder vorPers auf anfang stehen?
		 * ansonsten: 
		 * 
		 * Person *vorPers;
			Person *aktPers = anfang;
			int i;
			for(i=1; i < count-1; i++){ --dann muss aber eins kürzer gezählt werden
				vorPers=aktPers;
				aktPers=aktPers->next;
			}
		 * 
		 * */
		 
	Person *vorPers;
	Person *aktPers;
	int i;
	for(i=1; i < count; i++){
		vorPers=aktPers;
		aktPers=aktPers->next;
	}
	vorPers->next=aktPers->next;
	printf("%s\n",aktPers->name);
	anfang=aktPers->next;
	loeschen(aktPers);	
	return anfang;
}


int main (int argc, char *argv[]){
	
	/*argc = 8 wenn 7 Worte eingegeben*/
		
	Person *anfang = NULL;
	char name[25];
	
	while(scanf("%s", name) != EOF){
		anfang = einfuegen(name, anfang);
		printf("eingefuegt: %s\n", anfang->name);
	}
	
	while(anfang->next != anfang){
		anfang = abzaehlen(anfang, argc);
	}
	
	printf("%s -Gewinner/Looser\n",anfang->name);
	loeschen(anfang);
	
	return 0;
}
