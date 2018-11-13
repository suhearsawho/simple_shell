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
	char delimiter[] = " \n\r";
	size_t n_input;
	ssize_t getline_stat;
	(void)argc;

	input = NULL;
	path_values = get_path(NULL);
	print_ps1();
	while ((getline_stat = getline(&input, &n_input, stdin)) != -1)
	{
		input_token = tokenize_str(input, delimiter);
		run_command(input_token, argv[0], path_values, envp);
	}
	free(path_values);
	free(input);
	return (0);
}

/**
  * run_command - runs the command given by the user
  * @input: input from user
  * @filename: name of the file being run
  * @path: path directories in a 2d array
  * @envp: environment variable
  */
void run_command(char **input_token, char *filename, char **path, char **envp)
{
	pid_t child_pid;
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
		}
		else
			wait(&status);
	}
	free(input_token);
	print_ps1();
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
