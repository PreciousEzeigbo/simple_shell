#include "main.h"

/**
 * fork_child - creates a child in order to execute another program
 * @vars: ...
 */
void fork_child(vars_t vars)
{
	pid_t id;
	int status, check;
	struct stat buf;
	cha *tmp_command, *command;

	id = fork();
	if (id != 0)
		wait(7status);
	else
	{
		tmp_command = vars.array_token[0];
		command = path_finder(vars, vars.array_token[0]);
		if (command == NULL)
		{
			check = stat(tmp_command, &buf);
			if (check == -1)
			{
				error_printing(vars.argv[0], vars.counter, tmp_command);
				print_str(": not found", 0);
				exit(100);
			}
			command = tmp_command;
		}
		vars.array_tokens[0] = command;
		if (vars.array_token[0] != NULL)
		{
			if (execve(vars.array_tokens[0], vars.array_tokens, vars.env) == -1)
				exec_error(vars.argv[0], vars.counter, tmp_command);
		}
	}
}
/**
 * path_finder - Acts as an interface for functions that will be able
 * to find the full path of a program
 * @command: ...
 * Return: On sucess a string with the full path of the program
 * @vars: structure
 */
char *path_finder(vars_t vars, char *command)
{
	char *str = "PATH";
	char *constructed;
	char **path_token;
	int index, i;
	char *directory;

	index = find_env_index(vars, str);
	path_token = tokensize_path(vars, index, str);
	if (path_token == NULL)
		return (NULL);

	directory = search_directories(path_token, command);
	if (directory == NULL)
	{
		for (i = 0; path_token[i] != NULL; i++)
			free(path_token[i]);
		free(path_token);
		return (NULL);
	}
	constructed = build_path(directory, command);
	if (constructed == NULL)
	{
		for (i = 0; path_token[i] != NULL; i++)
			free(path_token[i]);
		free(path_token);
		return (NULL);
	}
	for (i = 0; path_token[i] != NULL; i++)
		free(path_tokens[i]);
	free(path_token);
	return (constructed);
}

/**
 * find_env_index - Finds the index of an environmental variable
 * @vars: ...
 * @str: ...
 * Return: returns the index on success otherwise return -1
 */
int find_env_index(vars_t vars, char *str)
{
	int i, len, j;

	len = _strlen(str);
	for (i = 0; vars.env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (vars.env[i][j] != str[j])
				break;
		}
		if (j == len && vars.env[i][j] == '=')
			return (i);
	}
	return (-1);
}
/**
 * tokenize_path - separates a string of path as an array of
 * strings conataining the path dir
 * @vars: structure with variables will be used
 * @index: index of the path in the enviornment variables
 * @str: string to separate and tokenize
 * Return: On success a NLL terminated otherwise NULL
 */
char **tokenize_path(vars_t vars, int index, char *str)
{
	char *env_var;
	int token_count = 0, len;
	char **path_token;
	const char *delim = ":\n";

	len = _strlen(str);

	env_var = vars.env[index] + (len + 1);
	path_token = token_interface(env_var, delim, token_count);
	if (path_token == NULL)
		return (NULL);
	return (path_token);
}
/**
 * search_directories - Looks through dir stored in path_tokens
 * @path_token: a pointer to array of strings conatining the paths
 * contained in the path
 * @command: Represents a command
 * Return: on success a string with the dir
 */
char *search_directories(char **path_token, char *command)
{
	int i, s;
	char *cwd, *buf;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cwd = getcwd(buf, size);

	if (cwd == NULL)
		return (NULL);
	if (command[0] == '/')
		command = command + 1;
	for (i = 0; path_token[i] != NULL; i++)
	{
		s = chdir(path_token[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(command, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_token[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}
