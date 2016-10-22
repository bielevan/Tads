#include <stdlib.h>
#include "tree_dynamic.h"

void create(TREE * t)
{
	t->root = NULL;
}

NO * insert(NO * no, elem e)
{
	if (no == NULL)
	{
		NO * n = (NO *) malloc (sizeof(NO));
		n->left = NULL;
		n->right = NULL;
		n->e = e;
		return e;
	}
	if (no->e >= e)
		no->left = insert(no->left, e);
	else
		no->right = insert(no->right, e);
	return no;
}

NO * remove(NO * no, elem e)
{
	if (no == NULL)
		return NULL;
	if (no->e > e)
		no->left = insert(no->left, e);
	else if (no->e < e)
		no->right = insert(no->right, e);
	else
	{
		NO * aux = no->right;
		if (aux == NULL)
		{
			NO * aux2 = no->left;
			free(no);
			return aux2;
		}
		NO * aux2 = aux;
		while (aux2->left != NULL)
			aux2 = aux2->left;
		aux2->left = no->left;
		free(no);
		return aux;
	}
	return no;
}

void show(NO * no)
{
	if (no == NULL)
		return;
	show(no->left);
	printf("%d ", no->e);
	show(no->right);
}

void clear(NO * no)
{
	if (no == NULL)
		return;
	clear(no->left);
	clear(no->right);
	free(no);
}

