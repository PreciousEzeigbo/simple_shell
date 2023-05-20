#include "shell.h"
/**
  * free_get_env - ...
  * @env_path: The environment variable to frees
  *
  * Return: Nothing to returns
  */
void free_get_env(char *env_path)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_path--;

	free(env_path);
}

/**
  * free_token - ...
  * @token: ...
  *
  * Return: Nothing to returns
  */
void free_token(char **token)
{
	char **temp = token;

	if (token)
	{
		while (*token)
			free(*token++);

		free(temp);
	}
}
