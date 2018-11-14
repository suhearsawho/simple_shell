#include "shell.h"

/**
  * main - entry point for simple shell
  * @argc: argument count
  * @argv: argument vector
  * @envp: argument environment
  * Return: 0 on success
  */
int main(int argc, char *argv[], char *envp[])
{
	char **path_values, **input_token, *input;
	char delimiter[] = " \n\r\t";
	size_t n_input;
	ssize_t getline_stat;
	shell_t shell_ptrs;

	(void)argc;
	input = NULL;
	path_values = get_path(NULL);
	print_ps1();
	while ((getline_stat = getline(&input, &n_input, stdin)) != -1)
	{
		input_token = tokenize_str(input, delimiter);
		shell_ptrs.path_values = path_values;
		shell_ptrs.input = input;
		shell_ptrs.input_token = input_token;
		if (run_build_in(&shell_ptrs))
			run_command(&shell_ptrs, argv[0], envp);
		free(input_token);
		print_ps1();
	}
	free(path_values);
	free(input);
	return (0);
}

/**
  * run_command - runs the command given by the user
  * @shell_ptrs: structure containing all malloced spaces
  * @filename: name of the file being run
  * @envp: environment variable
  */
void run_command(shell_t *shell_ptrs, char *filename, char **envp)
{
	pid_t child_pid;
	char **input_token = shell_ptrs->input_token;
	char **path = shell_ptrs->path_values;
	int status;

	if (input_token[0] != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(input_token[0], input_token, envp) == -1)
			{
				input_token[0] = find_pathname(path, input_token[0]);
				if (input_token[0] == NULL)
					printf("%s: No such file or directory\n", filename);
				else if (execve(input_token[0], input_token, envp) == -1)
					printf("%s: No such file or directory\n", filename);
				free(input_token[0]);
			}
			free(shell_ptrs->input);
			free(path);
			free(input_token);
			_exit(130);
		}
		else
			wait(&status);
	}
}

/**
 * run_build_in - checks if the the user calls a built-in cmd.
 * @ptrs: contains all the malloced spaces.
 * Return: 1 for match not found, 0 for match found.
 */
int run_build_in(shell_t *ptrs)
{
	size_t index;

	built_t cmd[] = {
		{"exit", my_exit},
		{"env", print_env},
		{NULL, NULL},
	};

	if (!ptrs)
		return (1);
	if (!(ptrs->input_token[0]))
		return (1);

	index = 0;
	while (cmd[index].cmd_name)
	{
		if (!_strcmp(ptrs->input_token[0], cmd[index].cmd_name))
		{
			(cmd[index].cmd)(ptrs);
			return (0);
		}
		index++;
	}
	return (1);
}

/**
  * free_memory - frees memory allocated in main
  * @input: input string
  */
void free_memory(char **input)
{
	unsigned int i;

	for (i = 0; input[i] != NULL; i++)
		free(input[i]);
	free(input);
}
