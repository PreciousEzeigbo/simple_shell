#include "shell.h"

/**
 * handle_exit - handles the "exit" command
 * @u_token: ...
 * @line: ...
 *
 * Return: Nothing to returns
 */
void handle_exit(char **u_token, char *line)
{
	int status = 0;

	if (u_token[1] == NULL || (!_strcmp(u_token[1], "0")))
	{
		free_token(u_token);
		free(line);
		exit(0);
	}
	status = _atoi(u_token[1]);
	if (status != 0)
	{
		free_token(u_token);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(u_token[1]);
		_puts("\n");
		exit(2);
	}
	free_token(u_token);
	free(line);
	exit(EXIT_SUCCESS);
}
