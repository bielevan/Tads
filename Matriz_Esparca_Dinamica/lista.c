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

void inserirLista(LISTA * l, int id)
{
    NO * n = (NO *) malloc (sizeof(NO));
    n->id = id;
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

int inserirSemRepertirLista(LISTA * l, int id)
{
    NO * n = (NO *) malloc (sizeof(NO));
    n->id = id;
    n->prox = NULL;
    if (estaVaziaLista(l))
    {
        l->inicio = n;
        l->fim = n;
        return TRUE;
    }
    NO * aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            free(n);
            return FALSE;
        }
        aux = aux->prox;
    }
    l->fim->prox = n;
    l->fim = n;
    return TRUE;
}

int contem(LISTA * l, int id)
{
    NO * aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->id == id)
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

int inicioLista(LISTA * l)
{
    if (estaVaziaLista(l))
        return -1;
    return l->inicio->id;
}

int excluirLista(LISTA * l)
{
    NO * aux = l->inicio;
    int total = 0;
    while (aux != NULL)
    {
        NO * aux2 = aux;
        aux = aux->prox;
        total++;
        free(aux2);
    }
    return total;
}

void excluirNLista(LISTA * l, int qtn)
{
    NO * aux = l->inicio;
    while (aux != NULL && qtn-- > 0)
    {
        NO * aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    l->inicio = aux;
    if (l->inicio == NULL)
        l->fim = NULL;
}

int buscarLista(LISTA *l, int pos)
{
    NO * aux = l->inicio;
    for (int i = 1; i < pos && aux != NULL; i++)
        aux = aux->prox;

    if (aux == NULL)
        return -1;

    return aux->id;
}
