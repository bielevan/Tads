#define TRUE 1
#define FALSE 0

typedef int elem;

typedef struct no
{
	elem e;
	struct * left;
	struct * right;
}NO;

typedef struct tree
{
	NO * root;
}TREE;

void create(TREE * t);
void clear(NO * no);
void show(NO * no);
int height(NO * no);
NO * insert(NO * root, elem e);
NO * remove(NO * no, elem e);
