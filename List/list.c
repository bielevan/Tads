#include "list.h"

void create(LIST * L)
{
	L->start = NULL;
}

void insert(LIST * L, elem e)
{
	NO * no = (NO *) malloc (sizeof(NO));
	no->e = e;
	no->next = NULL;
	if (L->start == NULL)
	{
		L->start = no;
		return;
	}
	NO * aux = L->start;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = no;
}

void remove(LIST * L, elem e)
{
	if (L->start == NULL)
		return;
	NO * aux = L->start;
	NO * aux2 = NULL;
	while (aux != NULL)
	{
		if (aux->e == e)
		{
			if (aux2 == NULL)
			{
				L->start = aux->next;
				free(aux);
				return;
			}
			aux2->next = aux->next;
			free(aux);
			return;
		}
		aux2 = aux;
		aux = aux->next;
	}
}

void show(LIST * L)
{
	NO * aux = L->start;
	while (aux != NULL)
	{
		printf("%d ", aux->e);
		aux = aux->next;
	}
	printf("\n");
}
