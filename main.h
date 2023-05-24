#ifndef _SHELL_MAIN_
#define _SHELL_MAIN_
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct historyy - A structure for each command read
 * @str: string
 * @counter: number of inputs
 * @next: Next element
 */

typedef struct historyy
{
	char *str;
	int counter;
	struct historyy *next;

} history_t;

/**
 * struct variable - variables
 * @array_tokens: array of tokens(arguments)
 * @buffer: buffer of command
 * @status: to handle exit status
 * @argv: gets arguments at opening of shell
 * @counter: counts commands entered
 * @env: has environment
 * @commands: have commands
 * @history: structure
 * @invert: structure
 */
typedef struct variable
{
	char **array_tokens;
	char *buffer;
	int status;
	char **argv;
	int counter;
	char **env;
	char **commands;
	history_t *history;
	history_t *invert;

} vars_t;

/**
 * struct builtin - struct for the builtin function
 * @name: name of builtin commnd
 * @f: function for corresponding builtin
 */
typedef struct builtin
{
	char *name;
	void (*f)(vars_t *);
} builtin_t;

char *_strup(char *strtdup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
size_t _puts(char *str);
int _strlen(char *str);
void print_str(char *str, int new_line);
int _write_char(char c);
int print_number(int n);


void (*chaeck_for_buitin(vars_t *vars))(vars_t *vars);
void exit_new(vars_t *vars);
void env_(vars_t *vars);
void new_set(vars_t *vars);
void new_help(vars_t *vars);
void new_unset(vars_t *vars);
void cd_new(vars_t *vars);

char **tokensizee(char *buffer, char *delimiter);
unsigned int check_if_match(char c, const char *str);
char **_realoc(char **ptr, size_t *size);
char *new_strtok(char *str, const char *delim);

char **tokensize(int token_count, char *line, const char *delimiter);
char **token_interface(char *line, const char *delimiter, int token_count);
int count_token(char *line, const char *delimiter);

void check_for_path(vars_t *vars);

void _puts_error(char *str);
void prints_error_msg(vars_t *vars, char *msg);
char *integer_converter(unsigned int count);

int _atoi(char *str);

char **make_environment(char **env);
void free_env(char **env);

void new_help_exit(vars_t *vars);
void new_help_help(vars_t *vars);
void new_help_cd(vars_t *vars);
void new_help_env(vars_t *vars);
void new_help_historyy(vars_t *vars);
void new_help_unalias(vars_t *vars);
void new_help_unset(vars_t *vars);
void new_help_unsentenv(vars_t *vars);
void new_help_setenv(vars_t *vars);
void new_help_alias(vars_t *vars);
void new_help_else(vars_t *vars);

void new_setenv(vars_t *vars);
void add_key(vars_t *vars);
char *add_value(char *key, char *value);
char **find_key(char **env, char *key);
void setenv_cd(char **args, vars_t *vars);
void chdir_to_env(vars_t *vars, char *str);

void fork_kid(vars_t vars);
char *path_fin(vars_t vars, char *command);
int find_envindex(vars_t vars, char *str);
char **tokenize_path(vars_t vars, int index, char *str);
char *search_dir(char **path_tokens, char *command);
char *build_path(char *directory, char *command);

void error_print(char *av, int count, char *command);
void error_exec(char *av, int count, char *tmp_command);
void simple_error(void);
void print_cd_1(vars_t *vars);
void print_cd_2(vars_t *vars);

void new_history(vars_t *vars);
void *add_node(history_t **head, char *str);
void free_list(history_t *head);
ssize_t _putss(char *str);
void print_message(char *str);

void end_of_life(char *buffer);
unsigned int sig_flag;
#endif
