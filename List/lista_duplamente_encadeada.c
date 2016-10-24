#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

void create(LIST * L)
{
	L->start = NULL;
	L->size = 0;
}

void insert(LIST * L, elem e)
{
	NO * no = (NO *) malloc (sizeof(NO));
	no->e = e;
	if (L->start == NULL)
	{
		no->next = NULL;
		no->back = NULL;
		L->start = no;
		return;
	}
	NO * aux = L->start;
	while (aux->next != NULL)
		aux = aux->next;
	no->next = NULL;
	no->back = aux;
	aux->next = no;
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

void remove(LIST * L, elem e)
{
	NO
}



