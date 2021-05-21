#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument array
 * Return: 98 on error, 0 on success
 */
int main(int argc, char **argv)
{
	char *res = NULL;
	unsigned int n1Len, n2Len, resLen = 0, i;

	if (argc != 3)
	{
		printer("Error\n");
		exit(98);
	}

	if (hasnondigit(argv[1]) || hasnondigit(argv[2]))
	{
		printer("Error\n");
		exit(98);
	}

	n1Len = _strlen(argv[1]);
	n2Len = _strlen(argv[2]);
	resLen = n1Len + n2Len;

	res = (malloc(sizeof(char) * resLen));
	if (!res)
	{
		printer("Error\n");
		exit(98);
	}

	for (i = 0; i < resLen; i++)
		res[i] = 0;

	mul(argv[1], argv[2], res, n1Len, n2Len, resLen);
	_putchar('\n');

	free(res);
	return (0);
}

/**
 * mul - Multiplies 2 numbers and prints the result
 * @n1: Number 1
 * @n2: Number 2
 * @res: Result array
 * @n1Len: Length of @n1
 * @n2Len: Length of @n2
 * @resLen: Length of @res
 * Return: Nothing, function is void
 */
void mul(char *n1, char *n2, char *res, unsigned int n1Len, unsigned int n2Len,
		unsigned int resLen)
{
	int i, j, carry, nn1, nn2, i_f = 0, sum = 0;
	int i_s = 0;

	if (n1Len == 0 || n2Len == 0)
	{
		return;
	}

	for (i = n1Len - 1; i >= 0; i--)
	{
		carry = 0;
		nn1 = n1[i] - '0';
		i_s = 0;

		for (j = n2Len - 1; j >= 0; j--)
		{
			nn2 = n2[j] - '0';

			sum = nn1 * nn2 + res[i_f + i_s] + carry;
			carry = sum / 10;
			res[i_f + i_s] = sum % 10;
			i_s++;
		}
		if (carry > 0)
			res[i_f + i_s] += carry;
		i_f++;
	}

	i = resLen;
	while (i >= 0 && res[i] == 0)
		i--;

	if (i == -1)
	{
		_putchar('0');
		return;
	}

	while (i >= 0)
		_putchar(res[i--] + '0');
}

/**
 * _strlen - Gets the length of a string
 * @str: String
 * Return: Length of @str
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * hasnondigit - Confirms if a string contains only digits
 * @str: String to check
 * Return: 0 if string is pure, 1 if not
 */
int hasnondigit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

/**
 * printer - Printer function
 * @str: String to print
 * Return: Nothing, function is void
 */
void printer(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
