#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef struct listEle{
	char suchwort[25];
	char ersatzwort[25];
	struct listEle *next;
}ListEle;

ListEle *wordList;

ListEle *neuerKnoten(const char *such, const char*ersatz);

void addPair(const char *such, const char *ersatz);

void clearList(void);

typedef struct _Fundstelle{
	char *stelleImSuchstring;
	ListEle *ersetzung;
}Fundstelle; 

Fundstelle *find(const char *s);

int replaceAll(char *s);
