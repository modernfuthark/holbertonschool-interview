#include "menger.h"

char** alloc_sponge(int size);

/**
 * menger - Prints a 2D menger sponge
 * @level: Size of sponge
 * Return: Nothing, function is void
 */
void menger(int level)
{
	char **sponge = NULL;
	int size, i, j;

	size = pow(3, level);

	if (size > 0)
	{
		sponge = alloc_sponge(size);

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				printf("%c", sponge[i][j]);
			printf("\n");
		}
	}
}

char** alloc_sponge(int size)
{
	char **sponge;
	int i, j;

	sponge = malloc(sizeof(char *) * size);
	if (!sponge)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		sponge[i] = malloc(sizeof(char) * size);
		if (!sponge[i])
		{
			for (j = 0; j < i; j++)
			{
				free(sponge);
				free(*(sponge + j));
			}
			return (NULL);
		}
	}

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			sponge[i][j] = '0';
	return (sponge);
}
