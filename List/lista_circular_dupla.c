#include "lista_circular_dupla.h"

void criar(LISTA * L)
{
	L->tamanho = 0;
	L->inicio = NULL;
}

int tamanho(LISTA * L)
{
	return L->tamanho;
}

int estaVazia(LISTA * L)
{
	return (L->inicio == NULL) ? TRUE : FALSE;
}

void mostrar(LISTA * L)
{
	if (estaVazia(L))
		return;
	NO * aux = L;
	while (aux->prox != L)
	{
		printf("%d ", aux->e);
		aux = aux->prox;
	}
	if (aux != L)
		printf("%d ", aux->e);
	printf("\n");
}

void inserir(LISTA * L, elem e)
{
	NO * n = (NO * ) malloc (sizeof(NO));
	n->e = e;
	L->tamanho++:
	if (L->inicio == NULL)
	{
		n->prox = n;
		n->ant = n;
		L->inicio = n;
		return;
	}
	NO * aux = L->inicio;
	while (aux->prox != L->inicio)
		aux = aux->prox;
	n->prox = aux->prox;
	aux->prox->ant = n;
	aux->prox = n;
	n->ant = aux;
}

void remover(LISTA * L, elem e)
{
	if (estaVazia(L))
		return;
		
}








