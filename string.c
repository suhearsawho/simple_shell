#include "shell.h"

/**
  * _strlen - counts length of a string
  * @str: string
  * Return: number of string 
  */
size_t _strlen(char *str)
{
	size_t num_char;

	num_char = 0;
	while (*str++ != '\0')
		num_char++;
	return (num_char);
}
