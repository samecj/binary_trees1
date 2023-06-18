#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *               using the selection sort algorithm.
 *
 *@array: array of integers to sort.
 *@size: size of the array to sort.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_ptr, *current_ptr, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_ptr = &array[i];

		for (j = i + 1; j < size; j++)
		{
			current_ptr = &array[j];
			if (*current_ptr < *min_ptr)
				min_ptr = current_ptr;

		}

		if (min_ptr != &array[i])
		{
			temp = array[i];
			array[i] = *min_ptr;
			*min_ptr = temp;
			print_array(array, size);
		}
	}
}
