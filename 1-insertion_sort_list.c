#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	listint_t *current, *temp;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			if (temp->prev->prev != NULL)
				temp->prev->prev->next = temp;

			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next->prev = temp;

			print_list(*list);
		}
	}
}
