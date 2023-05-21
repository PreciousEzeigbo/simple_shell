#include "main.h"

/**
 * print_cd_1 - prints error when cd argument is invalid
 * @vars: vars parameter to inlude
 * Return: always return void and print a message
 */

void print_cd_1(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": invalid option", 0);
	print_str("cd: usage: cd [-] [--]", 0);
}

/**
 * print_cd_2 - prints the error message when cd argument doesn't exist
 * @vars: vars parameter to include
 * Return: always return void and print a message
 */

void print_cd_2(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": Not a directory", 0);
}
