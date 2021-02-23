#include "slide_line.h"

int left_slide(int *line, size_t size);
int right_slide(int *line, size_t size);

/**
 * slide_line - Merge neighboring cells if their numbers match
 * @line: Array to modify
 * @size: Size of array
 * @direction: Direction of merge
 * Return: 1 upon success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		return (left_slide(line, size));
	else if (direction == SLIDE_RIGHT)
		return (right_slide(line, size));
	else
		return (0);
}

/**
 * left_slide - Slide array to the left and merge
 * @line: Array to modify
 * @size: Size of array
 * Return: Always 1
 */
int left_slide(int *line, size_t size)
{
	int i, ahead, added = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
		{
			ahead = i;
			while (ahead < (int)size)
			{
				if (line[ahead] != 0)
				{
					line[i] = line[ahead];
					line[ahead] = 0;
					break;
				}
				ahead++;
			}
		}

		if (line[i] != 0)
		{
			if (i != 0 && line[i] == line[i - 1] && !added)
			{
				line[i - 1] *= 2;
				line[i] = 0;
				i--;
				added = 1;
			}
			else
				added = 0;
		}
	}
	return (1);
}

/**
 * right_slide - Slide awway to the right and merge
 * @line: Array to modify
 * @size: Size of array
 * Return: Always 1
 */
int right_slide(int *line, size_t size)
{
	int added = 0, i, ahead;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
		{
			ahead = i;
			while (ahead >= 0)
			{
				if (line[ahead] != 0)
				{
					line[i] = line[ahead];
					line[ahead] = 0;
					break;
				}
				ahead--;
			}
		}

		if (line[i] != 0)
		{
			if (i + 1 < (int)size && line[i] == line[i + 1] && !added)
			{
				line[i + 1] *= 2;
				line[i] = 0;
				i++;
				added = 1;
			}
			else
				added = 0;
		}
	}

	return (1);
}
