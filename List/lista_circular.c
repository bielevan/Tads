#include "lista_circular.h"

void criar(LISTA * L)
{
	L->inicio = NULL;
	L->tamanho = 0;
}

int estaVazia(LISTA * L)
{
	return (L->inicio == NULL) ? TRUE : FALSE;
}

int tamanho(LISTA * L)
{
	return L->tamanho;
}

void mostrar(LISTA * L)
{
	if (estaVazia(L))
		return;
	NO * aux = L->inicio;
	while (aux->prox != L->inicio)
	{
		printf("%d ", aux->e);
		aux = aux->prox;
	}
	printf("\n");
}

void inserir(LISTA * L, elem e)
{
	NO * n = (NO *) malloc (sizeof(NO));
	n->e = e;
	L->tamanho++;
	if (L->inicio == NULL)
	{
		n->prox = n;
		L->inicio = n;
		return;
	}
	NO * aux = L->inicio;
	while (aux->prox != L->inicio)
		aux = aux->prox;
	aux->prox = n;
	n->prox = L->inicio;
}

void remover(LISTA * L, elem e)
{
	if (estaVazia(L))
		return;
	NO * aux = L->inicio;
	NO * aux2 = NULL;
	while (aux->prox != L->inicio)
	{
		if (aux->e == e)
		{
			aux2->prox = aux->prox;
			free(aux);
			L->tamanho--;
			return;
		}
		aux2 = aux;
		aux = aux->prox;
	}
	if (aux->e == e)
	{
		L->tamanho--;
		if (aux2 == NULL)
		{
			free(aux);
			L->inicio = NULL;
			return;
		}
		aux2->prox = aux->prox;
		free(aux);
	}
}


