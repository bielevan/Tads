#include "queue_priority.h"
#include <stdlib.h>

void create(QUEUE * Q)
{
	Q->front = NULL;
	Q->back = NULL;
}

void push(QUEUE * Q, elem e, p priority)
{
	NO * no = (NO *) malloc (sizeof(NO));
	no->e = e;
	no->priority = priority;
	if (Q->front == NULL)
	{
		no->next = NULL;
		Q->front = no;
		Q->back = no;
		return;

	}
	NO * aux = Q->front;
	NO * aux2 = NULL;
	while (aux != NULL)
	{
		if (aux->priority > priority)
		{
			if (aux2 == NULL)
			{
				no->next = aux;
				Q->front = no;
				return;
			}
			no->next = aux;
			aux2->next = no;
			return;
		}
		aux2 = aux;
		aux = aux->next;
	}
	no->next = NULL;
	Q->back->next = no;
	Q->back = no;
}

int isEmpty(QUEUE * Q)
{
	return (Q->front == NULL) ? TRUE : FALSE;
}

void pop(QUEUE * Q)
{
	if (isEmpty(Q))
		return;
	NO * aux = Q->front;
	Q->front = Q->front->next;
	if (Q->front == NULL)
		Q->back = NULL;
	free(aux);
}

NO * top(QUEUE * Q)
{
	if (isEmpty(Q))
		return NULL;
	return Q->front;
}
