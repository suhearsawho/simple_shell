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
