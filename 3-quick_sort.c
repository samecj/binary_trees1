#include "sort.h"

int lomuto_partition(int *array, int low, int high, size_t size);
void qsort_recursive(int *array, int low, int high, size_t size);
/**
 * swap - Swaps two integers in an array.
 *
 * @a: A pointer to the first integer.
 * @b: A pointer to the second integer.
 *
 * Return: Nothing.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick sort algorithm and Lomuto partition scheme.
 *
 * @array: The array to sort.
 * @size:  The size of the array.
 *
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsort_recursive(array, 0, size - 1, size);
}

/**
 * qsort_recursive - Sorts a partition of an array of integers in ascending
 *                   order using the Quick sort algorithm and Lomuto partition
 *                   scheme recursively.
 *
 * @array: The array to sort.
 * @low:   The lowest index of the partition to sort.
 * @high:  The highest index of the partition to sort.
 * @size:  The size of the whole array.
 *
 * Return: Nothing.
 */
void qsort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p_index = lomuto_partition(array, low, high, size);

		qsort_recursive(array, low, p_index - 1, size);
		qsort_recursive(array, p_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions a section of an array of integers using
 *                    Lomuto partition scheme.
 *
 * @array: The array to partition.
 * @lower:   The lowest index of the partition to sort.
 * @higher:  The highest index of the partition to sort.
 * @size:  The size of the whole array.
 *
 * Return: The final index of the pivot element.
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int pivot = array[higher];
	int i = lower - 1, j = lower, temp = 0;

	for (; j < higher; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	i++;
	if (i != higher)
	{
		temp = array[i];
		array[i] = array[higher];
		array[higher] = temp;
		print_array(array, size);
	}

	return (i);
}
