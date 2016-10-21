#include "stack_static.h"

void create(STACK * S)
{
	S->top = -1;
}

int isEmpty(STACK * S)
{
	(S->top == -1) ? return TRUE : return FALSE;
}

int isFull(STACK * S)
{
	(S->top == MAX-1) ? return TRUE : return FALSE;
}

void push(STACK * S, elem e)
{
	if (isFull(S))
		return;
	S->vet[++S->top] = e;
}

void pop(STACK * S)
{
	if (isEmpty(S))
		return;
	S->top--;
}

int size(STACK * S)
{
	return S->top+1;
}

elem top()
{
	if (isEmpty(S))
		return -1;
	S->top--;
}

int size(STACK * S)
{
	return S->top+1;
}
