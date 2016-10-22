// Gabriel Ribeiro Evangelista
// Alysson Rogerio Oliveira
// Giovanni Campbell
#include <stdio.h>
#include <stdlib.h>
#include "queue_priority.h"

int main()
{
	QUEUE q;
	create(&q);
	int total;
	scanf("%d", &total);
	char c;
	int id, p;
	while (total-- > 0)
	{
		scanf(" %c %d %d", &c, &id, &p);
		push(&q, id, p);
	}
	scanf("%d", &total);
	while (1)
	{
		if (top(&q) == NULL)
			return 0;
		total -= top(&q)->priority;
		id = top(&q)->e;
		pop(&q);
		if (total >= 0)
			printf("%d ", id);
		else
			break;
	}
	while (top(&q) != NULL)
		pop(&q);
	return 0;
}
