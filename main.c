#include "shell.h"

/**
  * main - entry point for simple shell
  * @argc: argument count
  * @argv: argument vector
  * @envp: argument environment
  */
int main(int argc, char *argv[], char *envp[])
{
	char **path_values, **input_token, *input;
	char delimiter[] = " \n\r";
	size_t n_input;
	pid_t child_pid;
	int status;
	(void)argc;
	(void)argv;
	(void)envp;
	
	input = NULL;
	/* tokenize the PATH variable in environ */
	path_values = get_path(NULL);	
	
	/* print primary prompt */
	print_ps1();

	/* keep calling getline until getline receives EOF / -1 */
	while (getline(&input, &n_input, stdin) != -1)
	{	
	/* tokenize the string */
		input_token = tokenize_str(input, delimiter); 
		/* try running the command with execve */
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(input_token[0], input_token, envp) == -1)
			{	
				input_token[0] = find_pathname(path_values, input);
				if (input_token[0] == NULL)
					printf("%s: No such file or directory\n", argv[0]);
				if (execve(input_token[0], input_token, envp) == -1)
					printf("%s: No such file or directory\n", argv[0]);
			}
			/* TODO free memory in child process! */
			return (0);
		}	
		else
		{
			wait(&status);
		}
	/* free memory */
		free(input_token);
	/* print shell prompt again */
		print_ps1();
	}
	free(path_values);
	return (0);
}
