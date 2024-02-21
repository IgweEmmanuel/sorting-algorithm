#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the doubly linked list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *                      in ascending order using Cocktail shaker sort
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left, *right, *current;

	left = NULL;
	right = NULL;
	current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		right = current;
		if (swapped == 0)
			break;

		swapped = 0;
		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}

		left = current;
	} while (swapped);
}

