#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct no
{
	elem e;
	struct no * next;
}NO;

typedef struct stack
{
	int size;
	NO * top;
}STACK;

void create(STACK * S);

void push(STACK * S, elem e);

void pop(STACK * S);

elem top(STACK * S);

int size(STACK * S);

int isEmpty(STACK * S):
