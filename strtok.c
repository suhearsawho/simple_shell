#include "shell.h"

/**
  * _strtok - tokenizes a string
  * @str: string to tokenize
  * @delim: string that contains the delimiters
  * Return: pointer to position in string of a null terminated word.
  */
char *_strtok(char *str, const char *delim)
{
	static char *begin, *end;
	const char *delim_cpy;
	int word_found;
	char *track;

	if (begin == NULL)
	{
		if (str == NULL)
			return (NULL);
		begin = str;
	}
	else
	{
		if (str != NULL)
			begin = str;
		begin = end + 1;
	}
	if (delim == NULL)
		return (NULL);
	delim_cpy = delim;
	for (track = begin, word_found = 0; *track != '\0'; track++)
	{
		for (delim = delim_cpy; *delim != '\0' && *delim != *track; delim++)
			;
		if (*delim == '\0' && word_found == 0)
		{
			begin = track;
			word_found = 1;
		}
		else if (*delim != '\0' && word_found == 1)
			break;
	}
	if (word_found == 0)
	{
		begin = NULL;
		return (NULL);
	}
	*track = '\0';
	end = track;
	return (begin);
}
