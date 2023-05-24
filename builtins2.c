#include "main.h"
/**
 * cd_new - changes the current working directory
 * if no parameter is passed it will change to the HOME directory
 * @vars: a string rep. the input from thr uder
 */
void cd_new(vars_t *vars)
{
	int index;

	if (vars->array_tokens[1] == NULL)
	{
		index = find_envindex(*vars, "HOME");
		chdir((vars->env[index]) + 5);
	}
	else if (_strcmpr(vars->array_tokens[1], "-") == 0)
		print_str(vars->array_tokens[1], 0);
	else
		chdir(vars->array_tokens[1]);
}
