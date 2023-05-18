#include "shell.h"

/**
 * print_env - Prints the environments variables
 *
 * Return: nothing
 */
void print_env(void)
{
	int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		if (j != 0)
			_putchar('\n');
		i++;
	}
}
