#include "main.h"

/**
 * chaeck_for_builtin - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*chaeck_for_builtin(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	builtin_t check[] = {
		{"exit", exit_new},
		{"env", env_},
		{"setenv", new_set},
		{"unsetenv", new_unset},
		{"cd", cd_new},
		{"help", new_help},

		{NULL, NULL}};
	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(vars->array_tokens[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(vars);
	return (check[i].f);
}

/**
 * exit_new - exit program
 * @vars: variables
 * Return: void
 */
void exit_new(vars_t *vars)
{
	int status;

	if (_strcmp(vars->array_tokens[0], "exit") ==
			0 &&
		vars->array_tokens[1] != NULL)

	{
		status = _atoi(vars->array_tokens[1]);

		if (status == -1)
		{
			vars->status = 2;

			prints_error_msg(vars, ": Illegal number: ");
			print_message(vars->array_tokens[1]);
			print_message("\n");
			return;
		}
		vars->status = status;
	}
	free(vars->commands);
	free(vars->array_tokens);

	free_env(vars->env);
	free(vars->buffer);
	exit(vars->status);
}

/**
 * env_ - prints the current environment
 * @vars: struct of variables
 * REturn: void
 */
void env_(vars_t *vars)
{
	unsigned int i;

	for (i = 0; vars->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	vars->status = 0;
}

/**
 * new_set - create a new environment variable or edit
 * @vars: pointer to struct of variables
 * Return: void
 */
void new_set(vars_t *vars)
{
	char **key;
	char *var;

	if (vars->array_tokens[1] == NULL || vars->array_tokens[2] == NULL)
	{
		prints_error_msg(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	key = find_key(vars->env, vars->array_tokens[1]);
	if (key == NULL)
	{
		add_key(vars);
	}
	else
	{
		var = add_value(vars->array_tokens[1], vars->array_tokens[2]);
		if (var == NULL)
		{
			prints_error_msg(vars, NULL);
			free(vars->buffer);
			free(vars->array_tokens);
			free(vars->commands);
			free_env(vars->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}

/**
 * new_unset - remove an environment variable
 * @vars: ..
 * Return: void
 */
void new_unset(vars_t *vars)
{
	char **key, **newenv;
	unsigned int i, j;

	if (vars->array_tokens[1] == NULL)
	{
		prints_error_msg(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	for (i = 0; vars->env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * i);
	if (newenv == NULL)
	{
		prints_error_msg(vars, NULL);
		vars->status = 127;
		exit_new(vars);
	}
	for (i = 0; vars->env[i] != *key; i++)
		newenv[i] = vars->env[i];
	for (j = i + 1; vars->env[j] != NULL; j++, i++)
		newenv[i] = vars->env[j];
	newenv[i] = NULL;
	free(*key);
	free(vars->env);
	vars->env = newenv;
	vars->status = 0;
}
