#include "shell.h"

/**
 * my_exit - simple impl of exit.
 * @ptrs: structure containing all malloced memory
 */
void my_exit(shell_t *ptrs)
{
	free(ptrs->input_token);
	free(ptrs->input);
	free(ptrs->path_values);
	exit(130);
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
