#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: Pointer to the head of the list.
 **/
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *sorted, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    sorted = *list;
    current = sorted->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            /* Swap the nodes */
            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;

            if (current->prev == NULL)
                *list = current;
            else
                current->prev->next = current;

            /* Print the list after each swap */
            print_list(*list);
        }

        sorted = current;
        current = temp;
    }
}

