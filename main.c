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
		if (check_slash(input) == 1)
			run_path(&shell_ptrs, argv[0]);
		else
		{
			if (run_build_in(&shell_ptrs) == 1)
				run_command(&shell_ptrs, argv[0], envp);
		}
		free(input_token);
		print_ps1();
	}
	free(path_values);
	free(input);
	return (0);
}

/**
  * check_slash - checks if there are any slashes in the command
  * @str: input string
  * Return: 1 if slash is found 0 if slash is not found
  */
int check_slash(char *str)
{
	while (*str != '\0')
	{
		if (*str == '/')
			return (1);
		str++;
	}
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
	char *input_org;
	int status;

	if (input_token[0] != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			input_org = _strdup(input_token[0]);
			input_token[0] = find_pathname(path, input_token[0]);
			if (input_token[0] == NULL)
				printf("%s: 1: %s: not found\n", filename, input_org);
			else if (execve(input_token[0], input_token, envp) == -1)
				printf("%s: 1: %s: not found\n", filename, input_org);
			free(input_token[0]);
			free(shell_ptrs->input);
			free(path);
			free(input_token);
			free(input_org);
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
  * run_path - runs the command specified by the pathname
  * @shell_ptrs: structure containing all malloced memory
  * @filename: filename of the file
  * Return: still to be determined
  */
int run_path(shell_t *shell_ptrs, char *filename)
{
	pid_t child_pid;
	int status, exit_status;
	char **input_token = shell_ptrs->input_token;

	exit_status = 0;
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(input_token[0], input_token, environ) == -1)
		{
			exit_status = 127;
			printf("%s: No such file or directory\n", filename);
		}
		free(input_token);
		free(shell_ptrs->path_values);
		free(shell_ptrs->input);
		_exit(127);
	}
	else
		wait(&status);
	return (exit_status);
}
