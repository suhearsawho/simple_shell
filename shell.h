#ifndef SHELL_H
#define SHELL_H

/* struct declarations */
typedef struct cmds {
	char *command;
	int (*run_cmd)(char *);
} cmd_t;

typedef struct cmd_input {
	struct cmd_input *input;
	char *str;
} input_t;

extern char *environ;

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

/* prompt_util.c */
void print_ps1(void);
char *find_pathname(char **, char *);
char *_getenv(const char *);

/* function prototypes */
char *_strtok(char *, const char *);
ssize_t getline(char **, size_t *, FILE *);
#endif
