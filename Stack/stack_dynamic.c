#include <stdlib.h>
#include "stack_dynamic.h"

void create(STACK * S)
{
	S->top = NULL;
	S->size = 0;
}

int isEmpty(STACK * S)
{
	return (S->top == NULL) ? TRUE : FALSE;
}

int size(STACK * S)
{
	return S->size;
}

void push(STACK * S, elem e)
{
	NO * no = (NO *) malloc (sizeof(NO));
	no->e = e;
	no->next = S->top;
	S->top = no;
	S->size++;
}

void pop(STACK * S)
{
	if (isEmpty(S))
		return;
	NO * aux = S->top;
	S->top = S->top->next;
	S->size--;
	free(aux);
}

elem top(STACK * S)
{
	if (isEmpty(S))
		return -1;
	return S->top->e;
}
