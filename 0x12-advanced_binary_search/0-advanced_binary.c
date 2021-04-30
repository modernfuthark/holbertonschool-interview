#include "search_algos.h"

int recursiveSearch(int *array, size_t L, size_t R, int val, long int *index);

/**
 * advanced_binary - Preforms an advanced binary search
 * @array: Array to search
 * @size: Size of @array
 * @value: Value to search for
 * Return: Index of @value, -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	long int index = -1;

	if (!array)
		return (-1);

	return (recursiveSearch(array, 0, size - 1, value, &index));
}

/**
 * recursiveSearch - Recursive binary search
 * @array: Array to search
 * @L: Left index
 * @R: Right index
 * @val: Value to find
 * @index: Index follower
 * Return: Index of value, -1 if not found
 */
int recursiveSearch(int *array, size_t L, size_t R, int val, long int *index)
{
	size_t i = L, middle;

	if (L >= R)
	{
		if (*index == -1 && L == R)
			printf("Searching in array: %d\n", array[i]);
		return (*index);
	}

	printf("Searching in array: %d", array[i++]);
	while (i <= R)
		printf(", %d", array[i++]);
	printf("\n");

	middle = L + ((R - L) / 2);

	if (array[middle] == val)
	{
		*index = middle;
	}
	else
	{
		if (array[middle] < val)
			return (recursiveSearch(array, middle + 1, R, val, index));
	}

	return (recursiveSearch(array, L, middle, val, index));
}
