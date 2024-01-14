#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *tmp;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        while (tmp->prev != NULL && tmp->n < tmp->prev->n) {
            tmp->prev->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->prev = tmp->prev;

            tmp->next = tmp->prev;
            tmp->prev = tmp->prev->prev;
            tmp->next->prev = tmp;

            if (tmp->prev == NULL)
                *list = tmp;
            else
                tmp->prev->next = tmp;

            print_list(*list); 
        }
    }
}

