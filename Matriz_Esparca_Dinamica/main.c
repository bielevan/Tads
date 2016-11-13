// Gabriel Ribeiro Evangelista
// Alysson Rogerio
// Geovanni Campbell

#include <stdio.h>
#include "matriz_esparca.h"

int main()
{
    int vertices, arestas;
    scanf("%d %d", &vertices, &arestas);
    MATRIZ matriz;
    criar(&matriz);
    for (int i = 0; i < vertices; i++)
    {
        ID id;
        scanf("%d", &id);
        inserirVertice(&matriz, id);
    }
    for (int i = 0; i < arestas; i++)
    {
        ID id1, id2;
        scanf("%d %d", &id1, &id2);
        inserirAresta(&matriz, id1, id2);
    }
    int t;
    scanf("%d,", &t);

    printf("%d\n", grau(&matriz, t));
    printf("%.2f\n", grauMedio(&matriz, t));
    printf("%.2f\n", coeficienteDeAglomeracao(&matriz, t));
    printf("%d\n", grauHierarquico(&matriz, t, 2));
    return 0;
}

