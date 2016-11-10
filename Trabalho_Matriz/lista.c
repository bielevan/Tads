#include <stdlib.h>
#include "lista.h"

void criarLista(LISTA * l)
{
    l->inicio = NULL;
    l->fim = NULL;
}

int estaVaziaLista(LISTA * l)
{
    return (l->inicio == NULL) ? TRUE : FALSE;
}

void inserirLista(LISTA * l, ARESTA * A)
{
    NO * n = (NO *) malloc (sizeof(NO));
    n->A = A;
    n->prox = NULL;
    if (estaVaziaLista(l))
    {
        l->inicio = n;
        l->fim = n;
        return;
    }
    l->fim->prox = n;
    l->fim = n;
}

int contem(LISTA * l, ARESTA * A)
{
    NO * aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->A->id_coluna == A->id_coluna)
            return TRUE;
        aux = aux->prox;
    }
    return FALSE;
}

void removerInicioLista(LISTA * l)
{
    if (estaVaziaLista(l))
        return;
    NO * aux = l->inicio;
    l->inicio = l->inicio->prox;
    if (l->inicio == NULL)
        l->fim = NULL;
    free(aux);
}

ARESTA * inicioLista(LISTA * l)
{
    if (estaVaziaLista(l))
        return NULL;
    return l->inicio->A;
}

void excluirLista(LISTA * l)
{
    NO * aux = l->inicio;
    l->inicio = NULL;
    l->fim = NULL;
    while (aux != NULL)
    {
        NO * aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}
