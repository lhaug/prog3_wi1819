#include <stdio.h>
#include <string.h>
#include "a1.h"
#include <assert.h>
#include <stdlib.h>

ListEle *new(const char *n, int a){
  ListEle *neu;

  neu = malloc(sizeof(ListEle));
  assert(neu);
  strcpy(neu->name, n);
  neu->alter = a;
  neu->next = NULL;
  return neu;
}

ListEle *einfuegen (ListEle *lst, const char *n, int a){
  ListEle *neuerKnoten
  ListEle *aktEle;

  neuerKnoten = new(n, a);
  aktEle = lst;

  if(aktEle == NULL){
    return neuerKnoten;
  }else{
    while(aktEle->next){
      aktEle = aktEle->next;
    }
    aktEle->next = neuerKnoten;
    return lst;
  }
  return NULL;
}

int dopple(ListEle *lst, const char *n, int a){
  ListEle *neuerKnoten;
  ListEle *aktEle;

  neuerKnoten = NULL;
  aktEle = lst;
  if(aktEle == NULL){
    return 0;
  }else{
    while(aktEle->next){
      if(strcmp(aktEle->name, n)==0){
        if(aktEle->alter == a){
          /*Element gefunden*/
          neuerKnoten = new(n, a);
          neuerKnoten->next = aktEle->next;
          aktEle->next = neuerKnoten;
          return 1;
        }
      }
      aktEle = aktEle->next;
    }
  }
  return 0;
}

void befreie(ListEle *lst){
  ListEle *aktEle;
  ListEle *del;

  while(aktEle){
    del = aktEle;
    aktEle = aktEle->next;
    free(del);
  }
}
