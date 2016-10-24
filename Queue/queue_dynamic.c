#include <stdlib.h>
#include "queue_static.c"

void create(QUEUE * Q)
{
	Q->front = NULL;
	Q->back = NULL;
}

void insert(QUEUE * Q, elem e)
{
	NO * no = (NO *) malloc (sizeof(NO));
	no->e = e;
	no->next = NULL;
	if (Q->front == NULL)
	{
		Q->front = no;
		Q->back = no;
		return;
	}
	Q->back->next = no;
	Q->back = no;
}

void pop(QUEUE * Q)
{
	if (Q->front == NULL)
		return;
	NO * aux = Q->front;
	Q->front = Q->front->next;
	if (Q->front == NULL)
		Q->back = NULL;
}

elem top(QUEUE * Q)
{
	if (Q->front == NULL)
		return -1;
	return Q->front->e;
}
