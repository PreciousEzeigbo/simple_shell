#include "shell"

/**
 * concat_path - concatenate a path name and a program name
 * @pathname: ...
 * @progname: ...
 *
 * Return: the path name concatenated with the program name
 */
char *concat_path(char *pathname, char *progname)
{
	int prog_len = 0, path_len = 0, new_sz = 0;

	prog_len = strlen(progname);
	path_len = _strlen(pathname);
	new_sz = sizeof(char) * (path_len + prog_len + 2);
	pathname = _realoc(pathname, (path_len + 1), new_sz);
	if (!pathname)
		return (NULL);

	_strcat(pathname, "/");
	_strcat(pathname, progname);

	return (pathname);
}
/**
 * find - searches for a command
 * @cname: The command name to find in the system
 *
 * Return: the path name of the command found or NULL if fail
 */
char *find(char *cname)
{
	char *env_path = NULL, **p_token = NULL;
	int i = 0, num_del = 0;
	struct stat sb;

	if (cname)
	{
		if (stat(cname, &sb) != 0 && cname[0] != '/')
		{
			env_path = getenv("PATH");
			num_del = count_delims(env_path, ":") + 1;
			p_token = tokenize(env_path, ":", num_del);

			while (p_token[i])
			{
				p_token[i] = concat_path(p_token[i], cname);

				if (stat(p_token[i], &sb) == 0)
				{
					free(cname);
					cname = _strup(p_token[i]);
					free_get_env(env_path);
					free_token(p_token);
					return (cname);
				}
				i++;
			}
			free_get_env(env_path);
			free_token(p_token);
		}
		if (stat(cname, &sb) == 0)
			return (cname);
	}
	free(cname);
	return (NULL);
}
/**
 * exec - Execute commands with options
 * @cname: The command to execute
 * @opts: The options to the command
 *
 * Return: An integer status value
 */
int exec(char *cname, char **opts)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cname, opts, environ);
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (WIFEXITED(STATUS) == 0 && WIFSIGNALED(status) == 0);
	}
	return (0);
}
