#ifndef LISTA_H
#define LISTA_H

#include "matriz_esparca.h"

typedef struct no
{
    ARESTA * A;
    struct no * prox;
}NO;

typedef struct lista
{
    NO * inicio;
    NO * fim;
}LISTA;

void criarLista(LISTA * l);

void inserirLista(LISTA * l, ARESTA * A);

void removerInicioLista(LISTA * l);

void excluirLista(LISTA * l);

int estaVaziaLista(LISTA * l);

int contem(LISTA * l, ARESTA * A);

ARESTA * inicioLista(LISTA * l);

#endif
