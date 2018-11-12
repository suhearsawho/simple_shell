#ifndef SHELL_H
#define SHELL_H

typedef struct cmds {
	struct cmds *next;
	int (*run_cmd)(char *);
} cmd_t;

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

/* Susan's Additions */




/* Martin's Additions */
ssize_t _getline(char **, size_t *, FILE *);





#endif
