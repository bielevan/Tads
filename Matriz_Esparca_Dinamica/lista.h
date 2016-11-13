#ifndef LISTA_H
#define LISTA_H

#include "matriz_esparca.h"

typedef struct no
{
    int id;
    struct no * prox;
}NO;

typedef struct lista
{
    NO * inicio;
    NO * fim;
}LISTA;

void criarLista(LISTA * l);

void removerInicioLista(LISTA * l);

void inserirLista(LISTA * l, int id);

void excluirNLista(LISTA * l, int qtn);

int buscarLista(LISTA * l, int pos);

int excluirLista(LISTA * l);

int estaVaziaLista(LISTA * l);

int contem(LISTA * l, int id);

int inserirSemRepertirLista(LISTA * l, int id);

int inicioLista(LISTA * l);

#endif
