#include "stack_static.h"

void create(STACK * S)
{
	S->top = -1;
}

int isEmpty(STACK * S)
{
	return (S->top == -1) ? TRUE : FALSE;
}

int isFull(STACK * S)
{
	return (S->top == MAX-1) ? TRUE : FALSE;
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
