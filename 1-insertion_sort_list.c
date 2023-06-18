#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node;

	if (list == NULL || *list == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev_node = current->prev;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;
			current->prev = prev_node->prev;
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;
			current->next = prev_node;
			prev_node->prev = current;
			print_list(*list);
		}
	}
}
