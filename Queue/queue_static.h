#define MAX 100
#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct queue
{
	int top;
	int start;
	int size;
	elem vet[MAX];
}QUEUE;

void create(QUEUE * Q);
void insert(QUEUE * Q, elem e);
void pop(QUEUE * Q);
elem top(QUEUE * Q);
int size(QUEUE * Q);
int isEmpty(QUEUE * Q);
int isFull(QUEUE * Q);
