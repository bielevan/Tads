typedef int elem;
typedef int p;

typedef struct no
{
	elem e;
	p priority;
}NO;

typedef struct queue
{
	NO * front;
	NO * back;
	int size;
}QUEUE;

void create(QUEUE * Q);
void push(QUEUE * Q, elem e, p priority);
elem pop(QUEUE * Q);
int size(QUEUE * Q);
int isEmpty(QUEUE * Q);
