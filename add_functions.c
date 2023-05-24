#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match -1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * error_print - Prints an error when a command is not found
 * @count: A counter keeping track of the number of commands run on the shell
 * @av: The name of the program running the shell
 * @command: The specific command not being found
 */
void error_print(char *av, int count, char *command)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_number(count);
	print_str(": ", 1);
	print_str(command, 1);
}

/**
 * error_exec - Prints exec errors
 * @av: The name of the program running the shell
 * @count: ...
 * @tmp_command: ...
 */
void error_exec(char *av, int count, char *tmp_command)
{
	error_print(av, count, tmp_command);
	print_str(": ", 1);
	perror("");
	exit(1);
}

/**
* simple_error - prints an exec simple error
* Return: always void
*/
void simple_error(void)
{
	perror("Fatal Error");
	exit(100);
}
