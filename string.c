#include "shell.h"
#include <string.h>

extern char **environ;
/**
  * _strlen - counts length of a string
  * @str: string
  * Return: number of string
  */
size_t _strlen(char *str)
{
	char *s = str;
	size_t num_char;

	num_char = 0;
	while (*s++ != '\0')
		num_char++;
	return (num_char);
}

/**
 * _strdup - create an identical duplicate in new allocated memory.
 * @s: pointer to string to duplicate.
 *
 * Return: pointer to new memory address of duplicate.
 */
char *_strdup(char *s)
{
	size_t i, len;
	char *dup;

	i = len = 0;
	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

/**
 * get_path - get the env path and tokenizes it into a array.
 * @env: string of a path.
 *
 * Return: array / double pointer.
 */
char **get_path(char *env)
{
	char **token_ptr;
	char *path, *delim;

	delim = ":";
	if (!env)
		path = getenv("PATH");
	else
		path = env;
	token_ptr = tokenize_str(path, delim);
	return (token_ptr);
}

/**
 * tokenize_str - function that take a string split them up at a delimiters and
 * add them into a array.
 * @str: string to process.
 * @delim: delimiter to split at.
 *
 * Return: pointer to pointers
 */
char **tokenize_str(char *str, char *delim)
{
	size_t n_delim = 0;
	char *str_dup, *tok;
	char **tokens;

	if (!str || !delim)
		return (NULL);
	str_dup = _strdup(str);

	/* count the delimiters */
	tok = strtok(str_dup, delim);
	while (tok)
	{
		n_delim++;
		tok = strtok(NULL, delim);
	}
	/*free the str_dup*/
	free(str_dup);

	/* malloc for tokens based on n_delim + 1 for the Null */
	tokens = malloc(sizeof(char *) * (n_delim + 1));
	if (!tokens)
		return (NULL);

	/* tokenize str */
	tok = strtok(str, delim);
	n_delim = 0;
	while(tok)
	{
		tokens[n_delim] = tok;
		tok = strtok(NULL, delim);
		n_delim++;
	}
	tokens[n_delim] = NULL;

	return (tokens);
}
