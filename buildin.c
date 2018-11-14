#include "shell.h"

/**
 * my_exit - simple impl of exit.
 */
void my_exit(shell_t *ptrs)
{
	free(ptrs->input_token);
	free(ptrs->input);
	free(ptrs->path_values);
	exit(130);
}
