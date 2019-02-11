#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct StackEle{
	int wert;
	struct StackEle *next;
} StackEle;

typedef enum {OP_ADD='+', OP_MUL='*', OP_SUB='-', OP_MOD='%', OP_DROP, OP_DUP}Operation;

StackEle *neuerKnoten(int value){
	StackEle *new;
	new = malloc(sizeof(StackEle));
	assert(new);
	new->next = NULL;
	new->wert = value;
	return new;
}

StackEle *push (StackEle *stack, int value){
	StackEle *new;
	new = neuerKnoten(value);
	new->next = stack;
	return new;
}

void print(StackEle *stack){
	StackEle *akt;
	
	akt = stack;
	while(akt != NULL){
		printf("%d ", akt->wert);
		akt = akt->next;
	}
	printf("\n");
}

void operation(StackEle *stack, Operation op){
	int first;
	int second;
	StackEle *firstEle, *secondEle, *new;
	int erg = 0;
	new = NULL;
	
	firstEle = stack;
	if(firstEle == NULL){
		return;
	}
	first = firstEle->wert;
	secondEle = stack->next;
	if(secondEle == NULL){
		return;
	}
	second = secondEle->wert;
	
	if ( op == OP_ADD){
		erg = first + second;
	}else if( op == OP_MUL){
		erg = first * second;
	}else if( op == OP_SUB){
		erg = first - second;
	}else if( op == OP_MOD){
		erg = first%second;
	}else if( op == OP_DROP){
		stack->wert = secondEle->wert;
		stack->next = stack->next->next;
		free(secondEle);
		secondEle = NULL;
		return;
	}else if( op == OP_DUP){
		new = neuerKnoten(firstEle->wert);
		new->next = firstEle->next;
		firstEle->next = new;
		return;
	}
	
	firstEle->wert = erg;
	firstEle->next = firstEle->next->next;
	free(secondEle);
	
}

void freeAll(StackEle *stack){
	StackEle *del;
	while (stack != NULL){
		del = stack;
		stack = stack->next;
		free(del);
	}
}
int main(){
	StackEle *stack;
	
	stack = push(NULL, 7);
	stack = push(stack, 3);
	stack = push(stack, 5);
	stack = push(stack, 1);
	print(stack);
	operation(stack, OP_ADD);
	print(stack);
	operation(stack, OP_MUL);
	print(stack);
	operation(stack, OP_DUP);
	print(stack);
	operation(stack, OP_DUP);
	print(stack);
	stack = push(stack, 1);
	operation(stack, OP_ADD);
	print(stack);
	operation(stack, OP_MOD);
	print(stack);
	operation(stack, OP_DROP);
	print(stack);
	freeAll(stack);
	
	return 0;
}
