#include "queue_static.h"

void create(QUEUE * Q)
{
	Q->top = -1;
	Q->start = 0;
	Q->size = 0;
}

int isEmpty(QUEUE * Q)
{
	return (Q->start-1 == Q->top) ? TRUE : FALSE;
}

int isFull(QUEUE * Q)
{
	return (Q->start+1 == Q->top) ? TRUE : FALSE:
}

void insert(QUEUE * Q, elem e)
{
	if (isFull(Q))
		return;
	Q->vet[Q->top] = e;
	Q->top++;
	if (Q->top == MAX)
		Q->top = 0;
}

void pop(QUEUE * Q)
{
	if (isEmpty(Q))
		return;
	Q->start++;
	if (Q->start == MAX)
		Q->start = 0;
}
