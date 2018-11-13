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
	pid_t child_pid;
	int status;
	ssize_t getline_stat;
	(void)argc;

	input = NULL;
	path_values = get_path(NULL);
	if (isatty(0))
		print_ps1();
	while ((getline_stat = getline(&input, &n_input, stdin)) != -1)
	{
		input_token = tokenize_str(input, delimiter);
		if (input_token[0] != NULL)
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(input_token[0], input_token, envp) == -1)
				{
					input_token[0] = find_pathname(path_values, input);
					if (input_token[0] == NULL)
						printf("%s: No such file or directory\n", argv[0]);
					else if (execve(input_token[0], input_token, envp) == -1)
						printf("%s: No such file or directory\n", argv[0]);
					free(input_token[0]);
				}
				return (0);
			}
			else
				wait(&status);
		}
		if (isatty(0))
			print_ps1();
	}
	return (0);
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
