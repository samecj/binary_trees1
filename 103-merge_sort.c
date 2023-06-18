#include "sort.h"

void merge_subarray(int *subarray, int *temp_arr, size_t front, size_t mid,
				size_t back);
void merge_sort_recursive(int *subarray,
	       int *temp_arr, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @temp_arr: A temporary array to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarray(int *subarray, int *temp_arr, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, mid - front);

	printf("[right]: ");
	print_array(subarray + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		temp_arr[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		temp_arr[k++] = subarray[i];
	for (; j < back; j++)
		temp_arr[k++] = subarray[j];
	for (i = front, k = 0; i < back; i++)
		subarray[i] = temp_arr[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @temp_arr: A temporary array to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray,
	       int *temp_arr, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarray, temp_arr, front, mid);
		merge_sort_recursive(subarray, temp_arr, mid, back);
		merge_subarray(subarray, temp_arr, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *               order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_arr;

	if (array == NULL || size < 2)
		return;

	temp_arr = malloc(sizeof(int) * size);
	if (temp_arr == NULL)
		return;

	merge_sort_recursive(array, temp_arr, 0, size);

	free(temp_arr);
}
