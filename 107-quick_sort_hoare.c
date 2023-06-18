#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: pointer to first integer.
 * @b: pointer to the integer.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @i: The starting index of the subset to partition.
 * @j: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int i, int j)
{
	int pivot, above, below;

	pivot = array[j];


	for (above = i - 1, below = j + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);

		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * hoare_sort - Implements the quicksort algorithm through recursion.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * @i: The starting index of the array partition to order.
 * @j: The ending index of the array partition to order.
 */
void hoare_sort(int *array, size_t size, int i, int j)
{
	if (j - i > 0)
	{
		int part = hoare_partition(array, size, i, j);

		hoare_sort(array, size, i, part - 1);
		hoare_sort(array, size, part, j);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * the quicksort algorithm with the Hoare partition scheme.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
