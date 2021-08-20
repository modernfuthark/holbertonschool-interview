#include "substring.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * find_substring - Finds a substring within a string
 * @s: String to search
 * @words: List of words to find
 * @nb_words: Number of words
 * @n: Pointer to address of number of returned elements
 * Return: Allocated array with indexes of found words in s
 * NULL if nothing is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int w_len, s_len;
	int i, j;
	int found = 0, holder = 0, nb_c = nb_words;
	int *inxs;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	(*n) = 0;
	s_len = strlen(s);
	w_len = strlen(words[0]);
	inxs = malloc(sizeof(int) * s_len);
	if (!inxs)
		return (NULL);

	for (i = 0; i <= s_len - nb_words * w_len; i++)
	{
		found = 0, holder = 0;
		for (j = 0; j < nb_words; j++)
		{
			if ((found & (1 << j)) == 0 &&
				!strncmp(&s[i + holder * w_len], words[j], w_len))
			{
				found = found | 1 << j;
				j = -1;
				holder++;
			}
		}
		if (found == (1 << nb_c) - 1)
		{
			inxs[*n] = i;
			(*n)++;
		}
	}

	return (inxs);
}
