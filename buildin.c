#include "shell.h"

/**
 * my_exit - simple impl of exit.
 * @ptrs: structure containing all malloced memory
 */
void my_exit(shell_t *ptrs)
{
	int exit_status;
	unsigned int i;
	char *exit_str;

	exit_str = ptrs->input_token[1];
	exit_status = 130;
	if (exit_str != NULL)
	{
		exit_status = 0;
		for (i = 0; exit_str[i] != '\0'; i++)
			exit_status = exit_status * 10 + (exit_str[i] - '0');
	}
	free_shell_t(ptrs);
	exit(exit_status);
}

/**
  * print_env - prints out the current environment
  * @ptrs: structure containing all malloced memory
  */
void print_env(shell_t *ptrs)
{
	unsigned int i;

	(void)ptrs;
	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
