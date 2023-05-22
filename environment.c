#include "main.h"

/**
 * make_environment - make the shell environment from the environment
 * @env: ...
 * Return: pointer to the new environment
 */
char **make_environment(char **env)
{
	char **newenvironment = NULL;

	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenironment = malloc(sizeof(char *) * (i + 1));
	if (newenvironment == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenvironment[i] = _strdup(env[i]);
	newenivronment[i] = NULL;
	return (newenvironment);
}
/**
 * free_env - free the shell's environment
 * @env: ...
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
/**
 * chdir_to_env - goto the dir that points to the address of
 * the environment variable
 * @vars: ...
 * @str: ...
 * Return: always return void
 */
void chdir_to_env(vars_t *vars, char *str)
{
	int len, index;

	len = _strlen(str);
	index = find_env_index(*vars, str);
	chdir((vars->env[index]) + len + 1);
}
