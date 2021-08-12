#include "regex.h"
#include <stdio.h>

int recursive_checker(const char *s, const char *p);

/**
 * regex_match - Diet regex function, only supports * and .
 * @str: String to check
 * @pattern: Pattern to check against
 * Return: 1 if the pattern matches, 0 if not
 */

int regex_match(char const *str, char const *pattern)
{
	return (recursive_checker(str, pattern));
}

/**
 * recursive_checker - Performs a recursive pattern check against a string
 * @s: String to check
 * @p: Pattern to match against
 * Return: 1 if the pattern matches, 0 if not
 */
int recursive_checker(const char *s, const char *p)
{
	if (*(s + 1) == '\0' && *(p + 1) == '\0' && (*p == *s || *p == '.'))
		return (1);

	if (*(p + 1) != '\0' && *(p + 1) == *s && *p == '*')
		return (recursive_checker(s, p + 1));

	if (*(p + 1) == '*' && (*p != *s && *p != '.'))
		return (recursive_checker(s, p + 2));

	if ((*(s + 1) == '\0' && *p != '*') || *p == '\0')
		return (0);

	if (*p == '.' && *(p + 1) == '*' && *(p + 2) == *s && *(p + 3) != '.')
		return (recursive_checker(s, p + 1));

	if (*s == *p || *p == '.')
		return (recursive_checker(s + 1, p + 1));
	else if (*p == '*' && *s != '\0')
	{
		if (*(p - 1) == *s || *(p - 1) == '.')
			return (recursive_checker(s + 1, p));
		else
			return (recursive_checker(s + 1, p + 1));
	}
	if (*s == '\0')
		return (1);
	return (0);
}
