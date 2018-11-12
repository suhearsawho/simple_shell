#include <stdio.h>
#include "shell.h"

int main(void)
{
	char **paths;
	int i = 0;

	paths = get_path(NULL);

	while (paths[i])
	{
		printf("%d - %s\n", i, paths[i]);
		i++;
	}

	free(paths);
	return (0);
}
