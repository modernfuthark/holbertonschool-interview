#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sorter_core(int *arr, int *temp, int L, int R);
void merger(int *arr, int *temp, int L, int M, int R);

/**
 * merge_sort - Performs a merge sort
 * @array: Array to sort
 * @size: Size of @array
 * Return: Nothing, function is void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size <= 1)
		return;

	temp = malloc(sizeof(int) * size);

	if (!temp)
		return;

	memcpy(temp, array, size * sizeof(int));
	sorter_core(array, temp, 0, size);
	free(temp);
}

/**
 * sorter_core - Recursive function for merging
 * @arr: Array
 * @temp: Temp array
 * @L: Left
 * @R: Right
 * Return: Nothing, function is void
 */
void sorter_core(int *arr, int *temp, int L, int R)
{
	int M;

	if (R - L <= 1)
		return;

	M = (L + R) / 2;
	sorter_core(temp, arr, L, M);
	sorter_core(temp, arr, M, R);
	merger(arr, temp, L, M, R);
}

/**
 * merger - Merging function
 * @arr: Array
 * @temp: Temp array
 * @L: Left
 * @M: Middle
 * @R: Right
 * Return: Nothing, function is void
 */
void merger(int *arr, int *temp, int L, int M, int R)
{
	int i, iL, iR;

	printf("Merging...\n[left]: ");

	print_array(temp + L, M - L);

	printf("[right]: ");

	print_array(temp + M, R - M);

	for (i = iL = L, iR = M; i < R; i++)
	{
		if (iL < M && (iR >= R || temp[iL] <= temp[iR]))
			arr[i] = temp[iL++];
		else
			arr[i] = temp[iR++];
	}

	printf("[Done]: ");
	print_array(arr + L, R - L);
}
