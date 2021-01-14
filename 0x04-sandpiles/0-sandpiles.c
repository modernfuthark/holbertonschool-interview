#include "sandpiles.h"

/* In-file functions */
void pile_add(int grid1[3][3], int grid2[3][3]);
int pile_stability(int grid[3][3]);
void pile_print(int grid[3][3]);
void pile_topple(int grid[3][3]);

/**
 * sandpiles_sum - Computes the sum of 2 sandpile matrixes
 * @grid1: First grid
 * @grid2: Second grid
 * Return: Nothing, function is void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	pile_add(grid1, grid2); /* Initial addition */

	while (pile_stability(grid1)) /* Will continue, because 1 == Unstable */
	{
		pile_topple(grid1);
	}
}

/**
 * pile_add - Adds 2 sandpiles together
 * @grid1: First grid
 * @grid2: Seconds grid
 * Return: Nothing, function is void
 */
void pile_add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * pile_stability - Determines if a sandpile is stable
 * @grid: Grid to judge
 * Return: 0 if grid is stable, 1 otherwise
 */
int pile_stability(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
			{
				pile_print(grid);
				return (1);
			}
	return (0);
}

/**
 * pile_print - Prints a sandpile
 * @grid: Grid to print
 * Return: Nothing, function is void
 */
void pile_print(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
			if (j != 2)
				putchar(' ');
		}
		putchar('\n');
	}
}

/**
 * pile_topple - Topples an unstable sandpile
 * @grid: Pile to topple
 * Return: Nothing, function is void
 */
void pile_topple(int grid[3][3])
{
	int i, j;
	int toppleBuffer[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	}; /* Buffer used to get a "map" of where the grains are distributed */

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3) /* Too many grains, topple */
			{
				grid[i][j] -= 4;

				/**
				 * Checks if cells are valid, location key below
				 * i - 1 -> Up
				 * i + 1 -> Down
				 * j - 1 -> Left
				 * j + 1 -> Right
				 */
				if (i - 1 >= 0)
					toppleBuffer[i - 1][j] += 1;
				if (i + 1 <= 2)
					toppleBuffer[i + 1][j] += 1;
				if (j - 1 >= 0)
					toppleBuffer[i][j - 1] += 1;
				if (j + 1 <= 2)
					toppleBuffer[i][j + 1] += 1;
			}
		}
	}
	/* Apply the "map" to the main grid */
	pile_add(grid, toppleBuffer);
}
