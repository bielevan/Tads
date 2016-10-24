typedef int elem;

typedef struct no
{
	elem e;
	struct no * next;
}NO;

typedef struct list
{
	struct no * start;
}LIST;

void create(LIST * L);
void insert(LIST * L, elem e);
void remove(LIST * L, elem e);
void show(LIST * L);
