#include "sort.h"

/**
 * swap_integers - Swaps two integers in an array.
 * @a: A pointer to the first integer.
 * @b: A pointer to the second integer.
 */
void swap_integers(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap_integers(&array[i], &array[j]);
            print_array(array, high + 1);
        }
    }

    swap_integers(&array[i + 1], &array[high]);
    print_array(array, high + 1);

    return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the quicksort algorithm.
 * @array: The array to sort.
 * @low: The starting index of the partition to sort.
 * @high: The ending index of the partition to sort.
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high);

        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1);
}

