#include "palindrome.h"

unsigned long reverse(unsigned long i);

/**
 * is_palindrome - Checks if a given int is a palindrome
 * @n: Number to check
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev;

	rev = reverse(n);

	while (n != 0)
	{
		if (rev % 10 != n % 10)
			return (0);
		rev = rev / 10;
		n = n / 10;
	}

	return (1);
}

/**
 * reverse - Reverses a given number
 * @i: Number to reverse
 * Return: Reversed i
 */
unsigned long reverse(unsigned long i)
{
	unsigned long result = 0;

	while (i != 0)
	{
		result = result * 10 + (i % 10);
		i = i / 10;
	}

	return (result);
}
