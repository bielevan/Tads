#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct no
{
	elem e;
	struct no * prox;	
}NO;

typedef struct lista
{
	struct no * inicio;
	int tamanho;
}LISTA;

void criar(LISTA * L);
void inserir(LISTA * L, elem e);
void remover(LISTA * L, elem e);
void mostrar(LISTA * L);
int tamanho(LISTA * L);
int estaVazia(LISTA * L);
