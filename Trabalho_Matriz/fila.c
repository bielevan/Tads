#include <stdlib.h>
#include "fila.h"

void criarFila(FILA * F)
{
    F->inicio = NULL;
    F->fim = NULL;
    F->tamanho = 0;
}

int estaVaziaFila(FILA * F)
{
    return (F->inicio == NULL) ? TRUE : FALSE;
}

void inserirFila(FILA * F, ARESTA * A)
{
    NO_F * N = (NO_F *) malloc (sizeof(NO_F));
    N->A = A;
    N->prox = NULL;
    F->tamanho++;
    if (estaVaziaFila(F))
    {
        F->inicio = N;
        F->fim = N;
        return;
    }
    F->fim->prox = N;
    F->fim = N;
}

void removerFila(FILA * F)
{
    if (estaVaziaFila(F))
        return;
    F->tamanho--;
    NO_F * aux = F->inicio;
    F->inicio = F->inicio->prox;
    if (F->inicio == NULL)
        F->fim = NULL;
    free(aux);
}

void excluirFila(FILA * F)
{
    NO_F * aux = F->inicio;
    F->inicio = NULL;
    F->fim = NULL;
    while (aux != NULL)
    {
        NO_F * aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}

ARESTA * inicioFila(FILA * F)
{
    if (estaVaziaFila(F))
        return NULL;
    return F->inicio->A;
}
