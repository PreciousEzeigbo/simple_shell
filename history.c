#include "main.h"

/**
 * *add_node - Add node in the begining
 * @head: The pointer of the history list
 * @str: ...
 * Return: ON success 1
 */
void *add_node(history_t **head, char *str)
{
	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_list(*head);
	}
	new->str = _strup(str);
	if (new->str == NULL)
	{
		free_list(*head);
	}
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	copy = *head;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
	return (new);
}

/**
 * free_list - free pointers related with amalloc
 * @head: The ponter of the list
 *
 * Return: The number of elemntentss im the list
 */
void free_list(history_t *head)
{
	history_t *delete;

	if (!head)
		return;
	while (head)
	{
		delete = head->next;
		free(head->str);

		free(head);
		head = delete;
	}
	free(delete);
}
/**
 * new_history - print the list of a single list
 * @vars: ...
 * Return: the numnber of elements in the list
 */
void new_history(vars_t *vars)
{
	history_t *tmp = vars->history;
	history_t *tmp2 = vars->history;
	int i = 0, z = 1;
	unsigned int counter = 0;
	char *count;

	if (vars->array_tokens[1] != NULL)
	{
		prints_error_msg(vars, ": Command not found: ");
		print_message(vars->array_tokens[1]);
		print_message("\n");
		return;
	}
	else
	{
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		while (z < i)
		{
			counter++;
			count = integer_converter(counter);
			print_message(count);
			print_message("  ");
			_putss(tmp2->str);
			tmp2 = tmp2->next;
			z++;
			free(count);
		}
		tmp2 = tmp2->next;
		vars->invert = tmp2;
		free_list(tmp);
		free_list(tmp2);
		return;
	}
}
/**
 * _putss - writes a string to standard output
 * @str: ...
 * Return: number of chars printed or -1 on faiklure
 */
ssize_t _putss(char *str)
{
	ssize_t i, len;

	for (i = 0; str[i]; i++)
		;
	len = write(1, str, i);
	if (len != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
/**
 * print_message - print a string to standard output
 * @str: ...
 * Return: void
 */
void print_message(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("fatal error");
		exit(1);
	}
}
