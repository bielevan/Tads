#define TRUE 1
#define FALSE 0

typedef int elem;
typedef int p;

typedef struct no
{
	elem e;
	p priority;
	struct no * next;
}NO;

typedef struct queue
{
	NO * front;
	NO * back;
}QUEUE;

void create(QUEUE * Q);
void push(QUEUE * Q, elem e, p priority);
void pop(QUEUE * Q);
NO * top(QUEUE * Q);
int isEmpty(QUEUE * Q);
