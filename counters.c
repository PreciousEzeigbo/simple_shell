#include "shell.h"

/**
 * count_input - counts the number of input arguments
 * @str: The string of the word
 *
 * Return: number of words found in the string
 */
int count_input(char *str)
{
	int i = 0, cw = 0, state = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			cw++;
		}
		i++;
	}
	return (cw);
}
/**
 * count_delims - counts number of occurences of
 * delimiter characters in a string
 * @str: the string that contains delimiters
 * @del: ...
 *
 * Return: number of delimiters in the string
 */
int count_delims(char *str, char *del)
{
	int i = 0, j = 0, cw = 0;

	while (del[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == del[i])
				cw++;
			j++
		}
		i++;
	}
	return (cw);
}
