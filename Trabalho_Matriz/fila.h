#ifndef FILA_H
#define FILA_H

#include "matriz_esparca.h"

typedef struct no_f
{
    ARESTA * A;
    struct no_f * prox;
}NO_F;

typedef struct fila
{
    NO_F * inicio;
    NO_F * fim;
    int tamanho;
}FILA;

void criarFila(FILA * F);

void inserirFila(FILA * F, ARESTA * A);

void removerFila(FILA * F);

void excluirFila(FILA * F);

int estaVaziaFila(FILA * F);

ARESTA * inicioFila(FILA * F);

#endif
