#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 120

static ssize_t curbufsize = 0;
static size_t buf_index = 0;

static int buf_resize(char **src,char **buf);
static int appendtobuf(char *dest, char *src, ssize_t size);
static void *_bzero(void *buf, size_t size);
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
ssize_t _getline(char **linePtr, size_t *n, FILE *stream)
{
	ssize_t lineLen, rd;
	char *readbuf , *buffer;
	int success = 0;
	/* FILE type is struct and use a lot of function to interface with it */
	(void) stream;

	curbufsize = BUFSIZE;
	readbuf = buffer = NULL;
	if (!(*linePtr))
	{
		readbuf = malloc(sizeof(char) * BUFSIZE);
		*linePtr = readbuf;
		*n = BUFSIZE;
	}
	else
	{
		readbuf = *linePtr;
	}

	if (!readbuf)
		return (-1);
	lineLen = 0;
	
	while ((rd = read(STDIN_FILENO, readbuf, curbufsize)) - 1 > 0)
	{
		if (rd < 2)
			break;
		success = 1;
		if (readbuf[0] == EOF)
			break;
		lineLen += rd;
		if (rd == curbufsize)
		{
			if(buf_resize(&readbuf, &buffer) == -1)
				return (-1);
			buf_index = lineLen;
		}
		else if (buffer && (rd > 0))
			appendtobuf(buffer, readbuf, rd);

		_bzero(readbuf, curbufsize);
	}
	if (!success && rd == 1)
		return (0);
	else if (!success && rd < 0)
		return (-1);

	if (curbufsize >= BUFSIZE)
	{	
		free(*linePtr);
		*linePtr = readbuf;
	}
	*n = curbufsize;

	return (lineLen);
}

static int buf_resize(char **src,char **buf)
{
	char *temp;
	unsigned int i , j, init;

	temp = NULL;
	curbufsize *= 2;
	if (*buf)
	{
		temp = *buf;
		init = 0;
	}
	else
	{
		temp = *src;
		init = 1;
	}

	*buf = malloc(sizeof(char) * curbufsize);
	if (!buf)
		return (-1);
	i = j = 0;
	while (*src[j])
	{
		if (!init)
			while (temp || temp[i])
			{
				*buf[i] = temp[i];
				i++;
			}
		*buf[i] = *src[j];
		j++;
		i++;
	}
	free(temp);
	*src = malloc(sizeof(char) * curbufsize);
	if (!src)
		return (-1);
	return (0);
}

static int appendtobuf(char *dest, char *src, ssize_t size)
{
	ssize_t a, b;

	a = b = 0;
	while (b < size)
	{
		dest[buf_index + a] = src[b];
		a++;
		b++;
	}
	return (0);
}

static void *_bzero(void *buf, size_t size)
{
	if (size)
	{
		char *b = buf;

		do {
			*b++ = 0;
		} while (--size);
	}
	return (buf);
}
