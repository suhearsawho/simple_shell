#include "shell.h"

/**
  * _realloc - reallocates a memory block
  * @ptr: pointer
  * @old_size: original size
  * @new_size: new size
  * Return: pointer to new memory block
  */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *storage;
	size_t index;

	if (new_size == 0)
	{
		if (ptr != NULL)
		{
			free(ptr);
			return (NULL);
		}
		storage = malloc(new_size);
		return (storage);
	}
	else
	{
		if (new_size != old_size)
		{
			storage = malloc(new_size);
			if (storage == NULL)
				return (NULL);
			if (ptr != NULL)
			{
				for (index = 0; index < old_size && index < new_size; index++)
					((char *)storage)[index] = ((char *)ptr)[index];
				free(ptr);
			}
			return (storage);
		}
		return (ptr);
	}
}

/**
  * _realloc - reallocates a memory block
  * @ptr: pointer
  * @old_size: original size
  * @new_size: new size
  * Return: pointer to new memory block
  */
char **_environ_add(char *env)
{
	size_t index, env_size;
	char **new_environ;

	index = env_size = 0;
	if (!env)
	{
		perror("Error: new enviorment to add is NULL");
		return (environ);
	}

	while (environ[env_size])
		env_size++;

	/* plus one for new var and another for the NULL at the end */
	new_environ = malloc(sizeof(char *) * (env_size + 2));
	if (!new_environ)
	{
		perror("Error: failed allocate memory for new environ");
		return (environ);
	}

	/* copy pointer inside environ to new malloc */
	while (index < env_size)
	{
		new_environ[index] = environ[index];
		index++;
	}
	
	new_environ[index] = env;
	new_environ[index + 1] = NULL;

	return (new_environ);

}
