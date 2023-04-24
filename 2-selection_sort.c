#include "sort.h"

/**
 * swap_integers - Swap two nodes in a listint_t doubly-linked list.
 * @a: A pointer to the head of the doubly-linked list.
 * @b: A pointer to the first node to swap.
 *
 */

void swap_integers(int *a, int *b);
void swap_integers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap_integers(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}

