#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

static size_t BUFSIZE = 120;
static size_t buf_index = 0;

static int buf_resize(char **src,char **buf, size_t);
static int appendtobuf(char *dest, char *src, ssize_t size);
static void *_bzero(void *buf, size_t size, char c);
/**
 * _getline - getlin() read an entire line from stream.
 * @lineptr: pointer to assigned the address of the create buffer to or to add
 * the contents to if the pointer is already an malloc-allocated buffer.
 * @n: value that is updated to reflect the size of the buffer used or created
 * @stream: some input to read a line from.
 *
 * Return: On success the size of the string read in number of chars. On fail to
 * read (including end-of-file condition) -1 is returned.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t lnlen, rd;
	char *readbuf , *buffer;
	int success = 0;
	/* FILE type is struct and use a lot of function to interface with it */
	(void) stream;

	readbuf = NULL;
	buffer = NULL;
	if (*n > BUFSIZE)
		BUFSIZE = *n;
	if (!*lineptr)
		 *lineptr = readbuf = malloc(sizeof(char) * BUFSIZE);
	else
		readbuf = *lineptr;
	if (!readbuf)
		return (-1);
	lnlen = 0;

	while ((rd = read(STDIN_FILENO, readbuf, BUFSIZE)) > 0)
	{
		dprintf(1, "rd = %d\n", (int)rd);
		lnlen += rd;
		if ((size_t)rd < BUFSIZE)
			strtok(readbuf, "\r\n");
		if (lnlen == 1 || !readbuf[0])
			break;
		*n = BUFSIZE;
		success = 1;
		if ((size_t)rd == BUFSIZE)
		{
			printf("RESIZE");
			buf_index = lnlen;
			if(buf_resize(&readbuf, &buffer, (size_t)rd))
				return (-1);
			*lineptr = buffer;
			*n = BUFSIZE;
		}
		else if (buffer && (rd > 2))
		{
			appendtobuf(buffer, readbuf, rd);
			if ((size_t)rd < BUFSIZE)
				break;
		}
		else if (rd == 1)
		{
			break;
		}
	}
	if (!success && rd == 0)
	{
		return (-1);
	}
	else if (!success)
	{
		return (0);
	}

	if ((size_t)lnlen > 120)
		free(readbuf);

	return (lnlen);
}

static int buf_resize(char **src,char **buf , size_t limit)
{
	char *temp;
	unsigned int i , j, init = 1;
	size_t preSize = BUFSIZE;

	if (limit == 0)
		return (0);
	temp = NULL;
	BUFSIZE *= 2;

	if (*buf)
	{
		temp = *buf;
		init = 0;
	}
	*buf = malloc(sizeof(char) * BUFSIZE);
	if (!buf)
		return (1);
	i = j = 0;
	while (j < limit)
	{
			while (i < preSize)
			{ 
				if (init)
					(*buf)[i] = (*src)[i];
				else
					(*buf)[i] = temp[i];
				i++;
			}
			if (init)
				break;
		(*buf)[i] = (*src)[j];
		j++;
		i++;
	}
	free(temp);
	free((*src));
	*src = malloc(sizeof(char) * BUFSIZE);
	if (!*src)
		return (1);
	return (0);
}

static int appendtobuf(char *dest, char *src, ssize_t size)
{
	ssize_t a, b;

	a = b = 0;
	while (b < size && ((buf_index + a) < BUFSIZE))
	{
		dest[buf_index + a] = src[b];
		a++;
		b++;
	}
	return (0);
}

static void *_bzero(void *buf, size_t size, char c)
{
	if (size)
	{
		char *b = buf;

		do {
			*b++ = c;
		} while (--size);
	*b = '\n';
	}
	return (buf);
}
