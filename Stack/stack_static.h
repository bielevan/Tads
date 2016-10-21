#define MAX 100
#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct stack
{
	int top;
	elem vet[MAX];
}STACK;

// Create stack
void create(STACK * S);

// Insert the stack
void push(STACK * S, elem e);

// Remove the stack
void pop(STACK * S);

// Check if is empty
int isEmpty(STACK * S);

// Check if is full
int isFull(STACK * S);

// Size 
int size(STACK * S);

// Last element
elem top(STACK * S);

