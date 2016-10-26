#include "banco_de_memoria.c"

void criar(B * b)
{
	for (int i = 0; i < MAX-1; i++)
		b->vet[i].prox = i+1;
	b->vet[MAX-1].prox = -1;
	b->tamanho = 0;
	b->proximo = 0;
	b->topo = -1;
}

int estaVazia(B * b)
{
	return (b->tamanho == 0) ? TRUE : FALSE;
}

int estaCheia(B * b)
{
	return (b->proximo == -1) ? TRUE : FALSE;
}

void inserir(B * b, elem e)
{
	if (estaCheia(B))
		return;
	int pos = b->proximo;
	b->proximo = b->vet[pos].prox;
	b->vet[pos].e = e;
	b->vet[pos].prox = b->topo;
	b->topo = pos;
	b->tamanho++;
}

void inserirInicio(B * b, elem e)
{
	if (estaCheia(B))
		return;
	int pos = b->topo;
	int aux = -1;
	while (pos != -1)
	{
		aux = pos;
		pos = b->vet[b->topo].prox;
	}
	pos = b->proximo;
	b->proximo = b->vet[pos].prox;
	b->vet[pos].e = e;
	b->vet[pos].prox = aux;
	b->tamanho++;
}

int tamanho(B * b)
{
	return b->tamanho;	
}

void remover(B * b, int pos)
{
	if (estaVazia(B))
		return;
	if (pos >= MAX)
		return;
	b->vet[pos].prox = b->proximo;
	b->proximo = pos;
}
