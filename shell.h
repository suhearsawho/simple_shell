#ifndef SHELL_H
#define SHELL_H

/* struct declarations */
typedef struct cmds
{
	char *command;
	int (*run_cmd)(char *);
} cmd_t;

typedef struct cmd_input
{
	char *str;
	struct cmd_input *next;
} input_t;

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

/* string.c */
size_t _strlen(char *);
char *_strdup(char *);
char **get_path(char *env);
char **tokenize_str(char *str, char *delim);

/* prompt_util.c */
void print_ps1(void);

/* function prototypes */
char *_strtok(char *, const char *);
ssize_t getline(char **, size_t *, FILE *);

#endif
