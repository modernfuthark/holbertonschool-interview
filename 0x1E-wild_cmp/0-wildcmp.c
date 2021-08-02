#include "holberton.h"
#include <stdio.h>


/**
 * wildcmp - Compairs 2 strings, taking into account the * wildcard
 * @s1: String 1
 * @s2: String 2
 * Return: 1 if strings are the same, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s1 != *s2)
	{
		if (*s2 == '*')
		{
			if (*(s1 + 1) == '*')
				return (wildcmp(s1, s2 + 1));
			if (*(s2 + 1) == '\0' && *s1 == '\0')
				return (1);
			return (wildcmp(s1 + secondary_compair((_strlen(s1) - 1), s1, s2), s2 + 1));
		}
		return (0);
	}
	return (1);
}

/**
 * _strlen - Gets the length of a string, recursivly
 * @str: String to check
 * Return: Length of string @str, 0 if string isnt found
 */
int _strlen(char *str)
{
	if (*str)
		return (1 + _strlen(str + 1));
	return (0);
}

/**
 * secondary_compair - Find next matching point in 2 strings
 * @i: Counting variable
 * @s1: String 1
 * @s2: String 2
 * Return: index of next matching point, 0 if not found
 */
int secondary_compair(int i, char *s1, char *s2)
{
	if (*(s1 + i) == *(s2 + 1))
		return (i);
	else if (*(s1 + i) == '\0')
		return (0);
	return (secondary_compair(i - 1, s1, s2));
}
