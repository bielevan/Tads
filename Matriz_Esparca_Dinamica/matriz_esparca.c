#include <stdlib.h>
#include "lista.h"

// Cria uma nova matriz esparça
void criar(MATRIZ * matriz)
{
    matriz->no_cb->id = -1;
    matriz->no_cb->proxcol = matriz->no_cb;
    matriz->no_cb->proxlin = matriz->no_cb;
}

// Retorna vertice com id informado
ARESTA * buscarLinha(MATRIZ * matriz, ID id)
{
    ARESTA * aux = matriz->no_cb->proxlin;
    while (aux != matriz->no_cb)
    {
        if (aux->id == id)
            return aux;
        aux = aux->proxlin;
    }
    return NULL;
}

// Retorna vertice com id informado
ARESTA * buscarColuna(MATRIZ * matriz, ID id)
{
    ARESTA * aux = matriz->no_cb->proxcol;
    while (aux != matriz->no_cb)
    {
        if (aux->id == id)
            return aux;
        aux = aux->proxcol;
    }
    return NULL;
}

// Inserir um novo vértice na matriz esparça
// Recebe como parametro o matriz e o id do vértice
void inserirVertice(MATRIZ * matriz, ID id)
{
    ARESTA * linha = (ARESTA *) malloc (sizeof(ARESTA));
    ARESTA * coluna = (ARESTA *) malloc (sizeof(ARESTA));
    linha->id = id;
    linha->id_linha = id;
    linha->id_coluna = id;
    coluna->id = id;
    coluna->id_linha = id;
    coluna->id_coluna = id;

    // Não existe vertice inserido
    if (matriz->no_cb->proxcol == matriz->no_cb)
    {
        matriz->no_cb->proxcol = coluna;
        coluna->proxcol = matriz->no_cb;
        coluna->proxlin = coluna;

        matriz->no_cb->proxlin = linha;
        linha->proxlin = matriz->no_cb;
        linha->proxcol = linha;
        return;
    }

    // Insere mais uma coluna
    ARESTA * aux = matriz->no_cb->proxcol;
    while (aux->proxcol != matriz->no_cb && aux->proxcol->id < id)
        aux = aux->proxcol;
    coluna->proxcol = aux->proxcol;
    aux->proxcol = coluna;
    coluna->proxlin = coluna;

    // Insere mais uma linha
    aux = matriz->no_cb->proxlin;
    while (aux->proxlin != matriz->no_cb && aux->proxlin->id < id)
        aux = aux->proxlin;
    linha->proxlin = aux->proxlin;
    aux->proxlin = linha;
    linha->proxcol = linha;
}

// Insere um nova aresta na matriz esparça
// Recebe como parametro o matriz, os ids dos dois nós que seram conectados
int inserirAresta(MATRIZ * matriz, ID no1, ID no2)
{
    // Obter posicao da linha e da coluna
    ARESTA * aux_linha, * aux_coluna;
    aux_linha = buscarLinha(matriz, no1);
    aux_coluna = buscarColuna(matriz, no2);

    // Verifica se a linha ou a coluna não existe
    if (aux_linha == NULL || aux_coluna == NULL)
        return FALSE;

    // Percorre linhas
    ARESTA * aux = aux_linha;
    while (aux_linha->proxcol != aux && aux_linha->proxcol->id_coluna < no2)
        aux_linha = aux_linha->proxcol;

    // Percorre colunas
    aux = aux_coluna;
    while (aux_coluna->proxlin != aux && aux_coluna->proxlin->id_linha < no1)
        aux_coluna = aux_coluna->proxlin;

    // Insere a primeira aresta
    ARESTA * aresta1 = (ARESTA *) malloc (sizeof(ARESTA));
    aresta1->id = 0;
    aresta1->id_linha = no1;
    aresta1->id_coluna = no2;
    aresta1->proxcol = aux_linha->proxcol;
    aresta1->proxlin = aux_coluna->proxlin;
    aux_linha->proxcol = aresta1;
    aux_coluna->proxlin = aresta1;

    // Obter posicao da linha e da coluna
    aux_linha = buscarLinha(matriz, no2);
    aux_coluna = buscarColuna(matriz, no1);

    // Percorre colunas
    aux = aux_linha;
    while (aux_linha->proxcol != aux && aux_linha->proxcol->id_coluna < no1)
        aux_linha = aux_linha->proxcol;

    // Percorre linhas
    aux = aux_coluna;
    while (aux_coluna->proxlin != aux && aux_coluna->proxlin->id_linha < no2)
        aux_coluna = aux_coluna->proxlin;

    // Inserir aresta 2
    ARESTA * aresta2 = (ARESTA *) malloc (sizeof(ARESTA));
    aresta2->id = 0;
    aresta2->id_linha = no2;
    aresta2->id_coluna = no1;
    aresta2->proxcol = aux_linha->proxcol;
    aresta2->proxlin = aux_coluna->proxlin;
    aux_linha->proxcol = aresta2;
    aux_coluna->proxlin = aresta2;

    return TRUE;
}

// Verifica qual é o grau de um determinado nó
// Recebe como parametro o matriz e o id do nó
int grau(MATRIZ * matriz, ID id)
{
    ARESTA * aux = buscarLinha(matriz, id);
    if (aux == NULL)
        return 0;

    ARESTA * aux2 = aux->proxcol;
    int total = 0;
    while (aux2 != aux)
    {
        total++;
        aux2 = aux2->proxcol;
    }
    return total;
}

// Calcula o valor do grau de cada visinho do nó informado e obtem a média
// Recebe como parametro o matriz e ID do nó que deve-se calcular o grau médio
float grauMedio(MATRIZ * matriz, ID id)
{
    ARESTA * aux = buscarLinha(matriz, id);
    if (aux == NULL)
        return 0;
    
    ARESTA * aux2 = aux->proxcol;
    float total_grau = 0;
    float total_no = 0;
    while (aux2 != aux)
    {
        total_no++;
        total_grau += grau(matriz, aux2->id_coluna);
        aux2 = aux2->proxcol;
    }
    return total_grau/total_no;
}

// Verifica se existe uma aresta que conecta o no1 com o no2
// Recebe como parametro o matriz, no1 e o id do no2
int existeConexao(ARESTA * aresta, ID id)
{
    ARESTA * aux = aresta->proxcol;
    while (aux != aresta)
    {
        if (aux->id_coluna == id)
            return TRUE;
        aux = aux->proxcol;
    }
    return FALSE;
}

// Calcula o coeficiente de aglomeracao de um determinado no
// Recebe como parametro o matriz e o id do no que deseja-se calcular o coeficiente
float coeficienteDeAglomeracao(MATRIZ * matriz, ID id)
{
    ARESTA * aux = buscarLinha(matriz, id);
    if (aux == NULL)
        return 0;

    // Cria lista com todos os visinhos de aux
    LISTA L;
    criarLista(&L);

    ARESTA * aux2 = aux->proxcol;
    int cont = 0;
    while (aux2 != aux)
    {
        cont++;
        inserirLista(&L, aux2->id_coluna);
        aux2 = aux2->proxcol;
    }

    // Verifica o numero de arestas existentes entre os visinhos do vertice
    float total = 0;
    while (cont-- >= 1)
    {
        // Percorre todos os vizinhos de A
        // E verifica se esta na lista
        ARESTA * aux = buscarLinha(matriz, inicioLista(&L));
        ARESTA * aux2 = aux->proxcol;
        removerInicioLista(&L);
        while (aux2 != aux)
        {
            if (contem(&L, aux2->id_coluna))
                total++;
            aux2 = aux2->proxcol;
        }
    }
    excluirLista(&L);

    int Kx = grau(matriz, id);
    if (Kx <= 1)
        return 0;
    return (2*total)/(Kx*(Kx-1));
}

// Verifica a quantidade de nos que estam a uma distancia H do no1
// Recebe como parametro o matriz, o id do no e a distancia H
int grauHierarquico(MATRIZ * matriz, ID id, int H)
{
    LISTA L;
    criarLista(&L);
    inserirSemRepertirLista(&L, id);

    int visinhos = 1;
    int visitados = 0;
    while (H > 0)
    {
        int visinhos_aux = visinhos;
        visinhos = 0;

        while (visinhos_aux-- > 0)
        {
            visitados++;
            ARESTA * aux = buscarLinha(matriz, buscarLista(&L, visitados));
            ARESTA * aux2 = aux->proxcol;
            while (aux2 != aux)
            {
                if (inserirSemRepertirLista(&L, aux2->id_coluna))
                    visinhos++;
                aux2 = aux2->proxcol;
            }
        }

        if (visinhos_aux > 0)
            break;

        H--;
    }

    if (H > 0)
    {
        excluirLista(&L);
        return 0;
    }

    excluirNLista(&L, visitados);
    return excluirLista(&L);
}
