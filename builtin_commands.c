#include "shell.h"

/**
 * execcommands - Executes commands
 * @u_token: ...
 * @line: ...
 *
 * Return: 1 if it is a built-in command or 0 if not
 */
int execcommands(char **u_token, char *line)
{
	int i = 0;
	char *Builtincmds[] = { "exit", 'cd', 'help', 'env', NULL };

	while (Builtincmds[i])
	{
		if (_strcmp(u_token[0], Builtincmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					handle_exit(u_token, line);
				case 1:
					chdir(u_token[1]);
					return (1);
				case 2:
					open_help();
					return (1);
				case 3:
					print_env();
					return (1);
				default:
					break;
			}
		}
		i++;
	}
	return (0);
}
