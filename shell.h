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

/* string.c */
size_t _strlen(char *);
char *_strdup(char *);
char **get_path(char *env);
char **tokenize_str(char *str, char *delim);
int _strcmp(char *, char *);

/* prompt_util.c */
void print_ps1(void);
char *find_pathname(char **, char *);
char *_getenv(const char *);
char *make_pathname(char *, char *);

/* function prototypes */
char *_strtok(char *, const char *);
ssize_t getline(char **, size_t *, FILE *);

#endif
