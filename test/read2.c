#include <stdio.h>
#include <unistd.h>
ssize_t _getline(char **line, size_t n, FILE *stream)
{
	(void) stream;

		while ((n = read(0, *line, n)) > 0)
		{
			if (*line < n && *line > 1)
				return n;
			else if (n == 1)
				return 1;
		}
	return -1;
}
