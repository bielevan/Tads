#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct no
{
	elem e;
	struct no * prox;
	struct no * ant;
}NO;

typedef struct l
{
	int tamanho;
	struct l * inicio;
}LISTA;

void criar(LISTA * L);
void mostrar(LISTA * L);
void inserir(LISTA * L, elem e);
void remover(LISTA * L, elem e);
int estaVazia(LISTA * L);
int tamanho(LISTA * L);
