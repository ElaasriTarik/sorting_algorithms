#include "sort.h"

/**
 * insertion_sort_list - uses the insertion algorithm to sort items
 * @list: double pointer to the doubly linked list to sort
*/

void insertion_sort_list(listint_t **list)
{

	listint_t *node1, *node2, *p;

	if (list == NULL || !*list || !(*list)->next)
		return;

	node1 = (*list)->next;
	while (node1)
	{
		node2 = node1;
		node1 = node1->next;
		while (node2 && node2->prev)
		{
			if (node2->prev->n > node2->n)
			{
				p = node2->prev;
				/** swapping the nodes */
				if (p->prev)
					p->prev->next = node2;
				if (node2->next)
					node2->next->prev = p;
				if (p->next)
				p->next = node2->next;
				if (node2->prev)
				node2->prev = p->prev;
				p->prev = node2;
				node2->next = p;

				if (node2->prev == NULL)
					*list = node2;
				print_list((const listint_t *)*list);
			}
			else
				node2 = node2->prev;
		}

	}
}
