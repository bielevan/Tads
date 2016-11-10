#include <stdlib.h>
#include "lista.h"
#include "fila.h"

// Cria uma nova matriz esparça
void criar(GRAFO * grafo)
{
    grafo->no_cb->id = -1;
    grafo->no_cb->proxcol = grafo->no_cb;
    grafo->no_cb->proxlin = grafo->no_cb;
}

// Retorna vertice com id informado
ARESTA * buscarLinha(GRAFO * grafo, ID id)
{
    ARESTA * aux = grafo->no_cb->proxlin;
    while (aux != grafo->no_cb)
    {
        if (aux->id == id)
            return aux;
        aux = aux->proxlin;
    }
    return NULL;
}

// Retorna vertice com id informado
ARESTA * buscarColuna(GRAFO * grafo, ID id)
{
    ARESTA * aux = grafo->no_cb->proxcol;
    while (aux != grafo->no_cb)
    {
        if (aux->id == id)
            return aux;
        aux = aux->proxcol;
    }
    return NULL;
}

// Inserir um novo vértice na matriz esparça
// Recebe como parametro o grafo e o id do vértice
void inserirVertice(GRAFO * grafo, ID id)
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
    if (grafo->no_cb->proxcol == grafo->no_cb)
    {
        grafo->no_cb->proxcol = coluna;
        coluna->proxcol = grafo->no_cb;
        coluna->proxlin = coluna;

        grafo->no_cb->proxlin = linha;
        linha->proxlin = grafo->no_cb;
        linha->proxcol = linha;
        return;
    }

    // Insere mais uma coluna
    ARESTA * aux = grafo->no_cb->proxcol;
    while (aux->proxcol != grafo->no_cb)
        aux = aux->proxcol;
    aux->proxcol = coluna;
    coluna->proxcol = grafo->no_cb;
    coluna->proxlin = coluna;

    // Insere mais uma linha
    aux = grafo->no_cb->proxlin;
    while (aux->proxlin != grafo->no_cb)
        aux = aux->proxlin;
    aux->proxlin = linha;
    linha->proxlin = grafo->no_cb;
    linha->proxcol = linha;
}

// Insere um nova aresta na matriz esparça
// Recebe como parametro o grafo, os ids dos dois nós que seram conectados
int inserirAresta(GRAFO * grafo, ID no1, ID no2)
{
    // Obter posicao da linha e da coluna
    ARESTA * aux_linha, * aux_coluna;
    aux_linha = buscarLinha(grafo, no1);
    aux_coluna = buscarColuna(grafo, no2);

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
    aux_linha = buscarLinha(grafo, no2);
    aux_coluna = buscarColuna(grafo, no1);

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
// Recebe como parametro o grafo e o id do nó
int grau(GRAFO * grafo, ID id)
{
    ARESTA * aux = buscarLinha(grafo, id);
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
// Recebe como parametro o grafo e ID do nó que deve-se calcular o grau médio
float grauMedio(GRAFO * grafo, ID id)
{
    ARESTA * aux = buscarLinha(grafo, id);
    if (aux == NULL)
        return 0;

    ARESTA * aux2 = aux->proxcol;
    int total_grau = 0;
    int total_no = 0;
    while (aux2 != aux)
    {
        total_no++;
        total_grau += grau(grafo, aux2->id_coluna);
        aux2 = aux2->proxcol;
    }

    return (total_grau/total_no);
}

// Verifica se existe uma aresta que conecta o no1 com o no2
// Recebe como parametro o grafo, no1 e o id do no2
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
// Recebe como parametro o grafo e o id do no que deseja-se calcular o coeficiente
float coeficienteDeAglomeracao(GRAFO * grafo, ID id)
{
    ARESTA * aux = buscarLinha(grafo, id);
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
        inserirLista(&L, aux2);
        aux2 = aux2->proxcol;
    }

    // Verifica o numero de arestas existentes entre os visinhos do vertice
    int total = 0;
    while (cont-- >= 1)
    {
        // Percorre todos os vizinhos de A
        // E verifica se esta na lista
        ARESTA * aux = buscarLinha(grafo, inicioLista(&L)->id_coluna);
        ARESTA * aux2 = aux->proxcol;
        removerInicioLista(&L);
        while (aux2 != aux)
        {
            if (contem(&L, aux2))
                total++;
            aux2 = aux2->proxcol;
        }
    }
    excluirLista(&L);

    int Kx = grau(grafo, id);
    if (Kx <= 1)
        return 0;

    float r = (2*total)/Kx*(Kx-1);
    return r;
}

// Verifica a quantidade de nos que estam a uma distancia H do no1
// Recebe como parametro o grafo, o id do no e a distancia H
int grauHierarquico(GRAFO * grafo, ID id, int H)
{
    // Obter a quantidade de vertices
    int tamanho = 0;
    ARESTA * aux = grafo->no_cb->proxlin;
    while (aux != grafo->no_cb)
    {
        tamanho++;
        aux = aux->proxlin;
    }

    // Marca todos os nos como não visitados
    int visitados[tamanho];
    for (int i = 0; i < tamanho; i++)
        visitados[i] = FALSE;
    visitados[id-1] = TRUE;

    FILA F;
    criarFila(&F);
    inserirFila(&F, buscarLinha(grafo, id));
    int visinhos_atual = 1;

    while (H-- > 0)
    {
        // Total de visinhos que tera que visitar
        int visinhos = visinhos_atual;
        visinhos_atual = 0;

        while (visinhos-- > 0)
        {
            ARESTA * atual = inicioFila(&F);
            ARESTA * aux2 = atual->proxcol;
            removerFila(&F);

            // Enquanto ainda não visitou todos os visinhos
            while (aux2 != atual)
            {
                if (visitados[aux2->id_coluna-1] == FALSE)
                {
                    inserirFila(&F, buscarLinha(grafo, aux2->id_coluna));
                    visitados[aux2->id_coluna-1] = TRUE;
                    visinhos_atual++;
                }
                aux2 = aux2->proxcol;
            }
        }

        if (estaVaziaFila(&F))
            break;
    }

    int tam = F.tamanho;
    excluirFila(&F);
    return tam;
}
