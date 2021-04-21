#include "sort.h"

/**
 * heap_sort - Preforms a maximum heap sort on an array
 * @array: Array to sort
 * @size: Size of @array
 * Return: Nothing, function is void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		(array[0] ^= array[i]), (array[i] ^= array[0]), (array[0] ^= array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Builds a max heap
 * @arr: Array
 * @size: Adjustable size
 * @idx: Index
 * @truesize: True size of @arr, used for printing
 * Return: Nothing, function is void
 */
void heapify(int *arr, size_t size, int idx, size_t truesize)
{
	int lrg = idx;
	int compair = (2 * idx) + 1;

	if (compair < (int)size && arr[compair] > arr[lrg])
		lrg = compair;
	compair++;
	if (compair < (int)size && arr[compair] > arr[lrg])
		lrg = compair;
	if (lrg != idx)
	{
		(arr[idx] ^= arr[lrg]), (arr[lrg] ^= arr[idx]), (arr[idx] ^= arr[lrg]);
		print_array(arr, truesize);
		heapify(arr, size, lrg, truesize);
	}
}
