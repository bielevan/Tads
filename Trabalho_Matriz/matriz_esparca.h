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
}GRAFO;

void criar(GRAFO * grafo);

void inserirVertice(GRAFO * grafo, ID id);

int inserirAresta(GRAFO * grafo, ID no1, ID no2);

int grau(GRAFO * grafo, ID id);

int grauHierarquico(GRAFO * grafo, ID id, int H);

int existeAresta(ARESTA * aresta, ID id);

float grauMedio(GRAFO * grafo, ID id);

float coeficienteDeAglomeracao(GRAFO * grafo, ID id);

ARESTA * buscarLinha(GRAFO * grafo, ID id);

ARESTA * buscarColuna(GRAFO * grafo, ID id);

#endif
