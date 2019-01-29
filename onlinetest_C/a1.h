#ifdef A1_H
#define A1_H

typedef struct lst{ char name[20]; int alter; struct lst *next;} ListEle;

ListEle *einfuegen (ListEle *lst, const char *n, int a);
int dopple(ListEle *lst, const char *n, int a);
void befreie(ListEle *lst);

#endif
