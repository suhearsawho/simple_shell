#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/* header files */
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

/**
 * shell_env - stores address for pointer to free.
 * @path_val: pointer to path values
 * @input_buf: pointer to buffer that getline creates.
 * @cur_tok: pointers for input token.
 */
typedef struct shell_env
{
	char **path_values;
	char *input;
	char **input_token;

} shell_t;

/**
 * build_in_cmd - struct for out fuction pointer to deal with building coomands
 * @cmd_name: name of the cmd
 * @cmd: function pointer to run the cmd.
 */
typedef struct built_in_cmd
{
	char *cmd_name;
	void (*cmd)(shell_t *);
} built_t;

/* main.c */
int run_build_in(shell_t *);
void run_command(shell_t *, char *, char **);
void free_memory(char **);

/* string.c */
size_t _strlen(char *);
char *_strdup(char *);
char **tokenize_str(char *, char *);
int _strcmp(char *, char *);

/* prompt_util.c */
void print_ps1(void);
char *find_pathname(char **, char *);
char *_getenv(const char *);
char *make_pathname(char *, char *);
char **get_path(char *env);

/* buildin.c */
void my_exit(shell_t *);


/* function prototypes */
char *_strtok(char *, const char *);
ssize_t getline(char **, size_t *, FILE *);

#endif
