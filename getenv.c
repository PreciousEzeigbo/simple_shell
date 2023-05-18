#include "shell.h"

/**
 * getenv - Retrieves the value of an  environment variable
 * @name: The varaiable to find in the system environment
 *
 * Return: the content of the environment variable
 */
char *getenv(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[1])
	{
		if (_strncmp(name, environ[1], _strlen(name)) == 0)
		{
			env_var = _strup(environ[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}
	return (NULL);
}
