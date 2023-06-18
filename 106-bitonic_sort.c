#include "sort.h"
#include <math.h>

/**
 * print_range - prints a range of elements from an array
 * @array: the array to sort
 * @start: the start index of the range to print
 * @end: the end index of the range to print
 */
void print_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * compare_and_swap - swaps two elements in an array
 * if they are in the wrong order
 * @array: the array to sort
 * @i: the first index
 * @j: the second index
 * @direction: the sorting direction
 * (1 for ascending, 0 for descending)
 */
void compare_and_swap(int *array, int i, int j, int direction)
{
	if (direction == (array[i] > array[j]))
	{
		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * bitonic_merge - recursively merges two bitonic
 * sequences in the given direction
 * @array: the array to sort
 * @start: the start index of the first bitonic sequence
 * @count: the length of the bitonic sequence
 * @direction: the sorting direction (1 for ascending, 0 for descending)
 * @int_size: The size of the array
 */
void bitonic_merge(int *array, int start, int count,
		int direction, const int int_size)
{
	if (count > 1)
	{
		int k = count / 2;
		int i;

		for (i = start; i < start + k; i++)
			compare_and_swap(array, i, i + k, direction);

		bitonic_merge(array, start, k, direction, int_size);
		bitonic_merge(array, start + k, k, direction, int_size);
	}
}

/**
 * bitonicSort - recursively sorts a bitonic sequence
 * in the given direction
 * @array: the arrayi to sort
 * @start: the start index of the bitonic sequence
 * @count: the length of the bitonic sequence
 * @direction: the sorting direction (1 for ascending, 0 for descending)
 * @int_size: The size of the array
 */
void bitonicSort(int *array, int start, int count,
		int direction, const int int_size)
{
	int k = count;

	if (count > 1)
	{
		if (direction == 1)
			printf("Merging [%d/%d] (UP):\n", count, int_size);
		if (direction == 0)
			printf("Merging [%d/%d] (DOWN):\n", count, int_size);
		print_range(array, start, start + k - 1);

		k = count / 2;
		bitonicSort(array, start, k, 1, int_size);

		bitonicSort(array, start + k, k, 0, int_size);

		bitonic_merge(array, start, count, direction, int_size);
		if (direction == 1)
		{
			printf("Result [%d/%d] (UP):\n", count, int_size);
			print_range(array, start, start + 2 * k - 1);
		}
		if (direction == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", count, int_size);
			print_range(array, start, start + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers using the Bitonic Sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{

	int direction = 1;

	const int int_size = (int)size;

	if (size < 2 || !array)
		return;

	bitonicSort(array, 0, (int)size, direction, int_size);
}
