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

/**
  * p_commanderr - prints error for failed command
  * @command: command that was submitted by user
  * @filename: name of the file being run
  */
void p_commanderr(char *command, char *filename)
{
	char *error_message;
	char *error = ": command not found\n";
	size_t num_char, i;
	(void)filename;

	num_char = _strlen(error) + _strlen(command);
	error_message = malloc(sizeof(char) * (++num_char));

	i = 0;
	while (*command != '\0')
		error_message[i++] = *command++;
	while (*error != '\0')
		error_message[i++] = *error++;
	error_message[i] = '\0';
	write(STDERR_FILENO, error_message, num_char);
	free(error_message);
}

/**
 * setenv - set a enviorment vars to a value
 * @name: name of the variable to set.
 * @value: values the set the variable to.
 * @overwrite: 1 to overwrite the variable if it exist, 0 to not overwrite if
 * the variable exists
 *
 * Return: 0 on success, or -1 on error.
 */
int setenv(const char *name, const char *value, int overwrite)
{
	char **old_env, **new_env;
	char *new_value, *env, *delim = "=";
	size_t env_size = 0;

	while (environ[env_size])
		env_size++;
	env_size++;

	env = _getenv(name);
	if (!env && !overwrite)
		return (-1);
	else if (env && !overwrite)
		return (0);

	new_value = str_concat_delim(name, value, delim);

	if (!env)
		_realloc(environ, sizeof(char *) * env_size,
				sizeof(char *) * (env_size + 1);
		environ[env_size + 1] = new_value;
	else if (env)
		env = new_value;

	return (0);
}
