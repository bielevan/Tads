#include <stdio.h>
#include "matriz_esparca.h"

int main()
{
    int vertices, arestas;
    scanf("%d %d", &vertices, &arestas);
    GRAFO grafo;
    criar(&grafo);
    for (int i = 0; i < vertices; i++)
    {
        ID id = i+1;
        inserirVertice(&grafo, id);
    }
    for (int i = 0; i < arestas; i++)
    {
        ID id1, id2;
        printf("Informe os nos: ");
        scanf("%d %d", &id1, &id2);
        inserirAresta(&grafo, id1, id2);
    }

    printf("Grau do no 1: %n", grau(&grafo, 1));
    printf("Grau medio do no 1: %.2f\n", grauMedio(&grafo, 1));
    printf("Coeficiente do no 1: %.2f\n", coeficienteDeAglomeracao(&grafo, 1));
    printf("Grau hierarquico: %d\n", grauHierarquico(&grafo, 1, 2));
    return 0;
}

