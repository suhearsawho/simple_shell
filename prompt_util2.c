#include "shell.h"

/**
  * free_shell_t - frees elements in shell_t struct
  * @shell_ptrs: structure of malloced elements
  */
void free_shell_t(shell_t *shell_ptrs)
{
	free(shell_ptrs->path_values);
	free(shell_ptrs->input);
	free(shell_ptrs->input_token);
	free(shell_ptrs->modify_path);
}
