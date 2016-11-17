#include "tabela_hash.h"
#include <stdlib.h>
#include <string.h>

void criar(TABELA * T)
{
    for (int i = 0; i < MAX; i++)
      T->vet[i] = NULL;
}

int hash(char * nome)
{
  int tamanho = strlen(nome);
  int total = 0;
  for (int i = 0; i < tamanho; i++)
    total += (int)nome[i];
  return (total % 500);
}

void inserir(TABELA * T, char * nome, char * significado)
{
    int len_nome = strlen(nome);
    int len_sign = strlen(significado);

    NO * N = (NO *) malloc (sizeof(NO));
    N->nome = (char *) malloc (sizeof(char) * len_nome);
    N->significado = (char *) malloc (sizeof(char) * len_sign);
    N->prox = NULL;

    strcpy(N->nome, nome);
    strcpy(N->significado, significado);

    int pos = hash(nome);
    if (T->vet[pos] == NULL)
    {
      T->vet[pos] = N;
      return;
    }

    NO * aux = T->vet[pos];
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = N;
}

int tamanhoLista(NO * N)
{
  if (N == NULL)
    return 0;
  int total = 0;
  NO * aux = N;
  while (aux != NULL)
  {
    total++;
    aux = aux->prox;
  }
  return total;
}

int colisao(TABELA * T)
{
  int total = 0;
  for (int i = 0; i < MAX; i++)
    if (T->vet[i] != NULL)
      total += tamanhoLista(T->vet[i])-1;
  return total;
}

char * buscarSignificado(TABELA * T, char * nome)
{
  int pos = hash(nome);
  if (T->vet[pos] == NULL)
    return NULL;

  NO * aux = T->vet[pos];
  while (aux != NULL)
  {
    if (strncmp(aux->nome, nome, 8) == 0)
      return aux->significado;

    aux = aux->prox;
  }
  return NULL;
}

void excluirLista(NO * N)
{
  while (N != NULL)
  {
    NO * aux = N;
    N = N->prox;

    free(aux->nome);
    free(aux->significado);
    free(aux);
  }
}

void excluirTabela(TABELA * T)
{
  for (int i = 0; i < MAX; i++)
  {
    excluirLista(T->vet[i]);
    T->vet[i] = NULL;
  }
}

int maiorLista(TABELA * T)
{
  int maior = 0;
  for (int i = 0; i < MAX; i++)
  {
    int aux = tamanhoLista(T->vet[i]);
    if (maior < aux)
      maior = aux;
  }
  return maior;
}
