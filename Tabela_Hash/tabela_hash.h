#define TRUE 1
#define FALSE 0
#define MAX 500

typedef struct no
{
  char * nome;
  char * significado;
  struct no * prox;
}NO;

typedef struct
{
  NO * vet[MAX];
}TABELA;

void criar(TABELA * T);

void inserir(TABELA * T, char * nome, char * elemento);

void excluirLista(NO * N);

void excluirTabela(TABELA * T);

int hash(char * nome);

int colisao(TABELA * T);

int tamanhoLista(NO * N);

int maiorLista(TABELA * T);

char * buscarSignificado(TABELA * T, char * nome);
