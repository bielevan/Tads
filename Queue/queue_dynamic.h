#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct no
{
	elem e;
	struct no * next;
}NO;

typedef struct q
{
	struct no * front;
	struct no * back;
	int size;
}QUEUE;

void create(QUEUE * Q);
void insert(QUEUE * Q, elem e);
void pop(QUEUE * Q);
elem top(QUEUE * Q);
