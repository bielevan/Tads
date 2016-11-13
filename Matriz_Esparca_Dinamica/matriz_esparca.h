#ifndef MATRIZ_H
#define MATRIZ_H

#define TRUE 1
#define FALSE 0

typedef int ID;

typedef struct aresta
{
    ID id;
    ID id_linha;
    ID id_coluna;
    struct aresta * proxcol;
    struct aresta * proxlin;
}ARESTA;

typedef struct grafo
{
    ARESTA * no_cb;
}MATRIZ;

void criar(MATRIZ * matriz);

void inserirVertice(MATRIZ * matriz, ID id);

float grauMedio(MATRIZ * matriz, ID id);

float coeficienteDeAglomeracao(MATRIZ * matriz, ID id);

int inserirAresta(MATRIZ * matriz, ID no1, ID no2);

int grau(MATRIZ * matriz, ID id);

int grauHierarquico(MATRIZ * matriz, ID id, int H);

int existeAresta(ARESTA * aresta, ID id);

ARESTA * buscarLinha(MATRIZ * matriz, ID id);

ARESTA * buscarColuna(MATRIZ * matriz, ID id);

#endif
