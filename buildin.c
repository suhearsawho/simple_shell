#include "shell.h"

/**
 * my_exit - simple impl of exit.
 * @ptrs: structure containing all malloced memory
 */
void my_exit(shell_t *ptrs)
{
	unsigned int i;
	char *exit_str;

	exit_str = ptrs->input_token[1];
	errno = 130;
	if (exit_str != NULL)
	{
		errno = 0;
		for (i = 0; exit_str[i] != '\0'; i++)
			errno = errno * 10 + (exit_str[i] - '0');
	}
	free_shell_t(ptrs);
	exit(errno);
}

/**
  * print_env - prints out the current environment
  * @ptrs: structure containing all malloced memory
  */
void print_env(shell_t *ptrs)
{
	unsigned int i;
	char newline = '\n';

	(void)ptrs;
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &newline, 1);
	}
	errno = 0;
}
