#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct no
{
	elem e;
	struct no * next;
	struct no * back;
}NO;

typedef struct list
{
	int size;
	struct no * start;
}LIST;

void create(LIST * L);
void insert(LIST * L, elem e);
void remove(LIST * L, elem e);
void show(LIST * L);
int isEmpty(LIST * L);
