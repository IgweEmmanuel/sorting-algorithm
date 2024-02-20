#include "sort.h"

/**
 * insertion_sort_list - This function inserts in a linked list
 * @list: This is the parameter
 *
 * Return: returns new list with inserted value
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;
		next_node = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}

		if (insertion_point == NULL)
		{
			current = next_node;
			continue;
		}

		if (current->next != NULL)
			current->next->prev = current->prev;
		current->prev->next = current->next;

		if (insertion_point->next != NULL)
			insertion_point->next->prev = current;
		current->next = insertion_point->next;
		insertion_point->next = current;
		current->prev = insertion_point;

		current = next_node;

		print_list(*list);
	}
}

