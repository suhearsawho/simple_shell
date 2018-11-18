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
#include <errno.h>

/**
 * struct shell_env - stores address for pointer to free.
 * @path_values: pointer to path values
 * @input: pointer to buffer that getline creates.
 * @input_token: pointers for input token.
 *
 * Description: provides a storage for all elements that are malloced.
 */
typedef struct shell_env
{
	char **path_values;
	char *input;
	char **input_token;
	char *modify_path;
} shell_t;

/**
 * struct built_in_cmd - struct for different built in commands.
 * @cmd_name: name of the cmd
 * @cmd: function pointer to run the cmd
 *
 * Description: struct for different built in commands in our shell
 */
typedef struct built_in_cmd
{
	char *cmd_name;
	void (*cmd)(shell_t *);
} built_t;

/* main.c */
int run_build_in(shell_t *);
int run_command(shell_t *, char *, char **);
int run_path(shell_t *, char *);
int check_slash(char *);

/* string.c */
size_t _strlen(const char *);
char *_strdup(char *);
char **tokenize_str(char *, char *);
int _strcmp(char *, char *);
char *str_concat_delim(const char *, const char *, const char *);

/* prompt_util.c */
void print_ps1(void);
char *find_pathname(char **, char *);
char *_getenv(const char *);
char *make_pathname(char *, char *);
char **get_path(char **);
char **_getenv_ptr(const char *);
/* prompt_util2.c */
void free_shell_t(shell_t *);
void p_commanderr(char *, char *);
int _setenv(const char *, const char *, int);

/* buildin.c */
void my_exit(shell_t *);
void print_env(shell_t *);

/* function prototypes */
char *_strtok(char *, const char *);
ssize_t getline(char **, size_t *, FILE *);

/* mem_manage.c */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
