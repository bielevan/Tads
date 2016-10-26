#define TRUE 1
#define FALSE 0
#define MAX 100

typedef int elem;

typedef struct no
{
	elem e;
	int prox;
}NO;

typedef struct banco
{
	int tamanho;
	int proximo;
	int topo;
	int vet[MAX];
}B;

void criar(B * b);
void inserir(B * b, elem e);
void remover(B * b, int pos);
void inserirInicio(B * b, elem e);
int estaVazia(B * b);
int estaCheia(B * b);
int tamanho(B * b);
