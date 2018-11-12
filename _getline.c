#include "shell.h"
#include <stdio.h>
#include <unistd.h>


static size_t BUFSIZE = 120;

ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	ssize_t rd;
	size_t i = BUFSIZE;
	char *buf;
	
	(void) stream;

	if (*n > BUFSIZE)
		BUFSIZE = i = *n;
	if (!*line)
		buf = malloc(sizeof(char) * BUFSIZE);
	else
	{
		buf = *line;
		do {
			*buf++ = 0;
		} while (--i);
		buf = *line;
	}
	while ((rd = read(0, buf, BUFSIZE)) > 0)
	{
		strtok(buf, "\r\n");
		if (rd == 1 )
			return (0);
		*n = BUFSIZE;
		if ((size_t)rd == BUFSIZE)
			*n = BUFSIZE *= 2;
		*line = buf;
		if ((size_t)rd < BUFSIZE && rd > 1)
			return rd;
		else if (rd == 1)
			return 1;
	}
	return -1;
}
