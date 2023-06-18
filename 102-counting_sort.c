#include "sort.h"

/**
 * _bigest - Returns the largest number in an array of integers
 * @a: The integer array
 * @size: Size of the array
 * Return: The largest number
 */
int _bigest(int *a, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < a[i])
			k = a[i];
	}

	return (k);
}

/**
 * _memset - Creates an integer array and initializes all elements to 0
 * @size: Size of array
 *  Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc(size * sizeof(int));

	if (ptr != NULL)
	{
		for (i = 0; i < size; i++)
			ptr[i] = 0;
	}

	return (ptr);
}

/**
 * counting_sort - Sorts an array of integers using the counting sort algorithm
 * @array: The integer array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int max = 0;
	int *count_array = NULL, *sorted_array = NULL;

	if (size < 2)
		return;
	max = _bigest(array, size);
	count_array = _memset(max + 1);
	if (count_array == NULL)
		return;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= (size_t) max; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);

	sorted_array = malloc(size * sizeof(int));

	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = sorted_array[j];

	free(sorted_array);
	free(count_array);
}
