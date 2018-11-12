#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int v,i = 0;

	if (ac !=  2)
		exit(10);
	v = atoi(av[1]);
	while (++i < v)
		printf("%c", 'g');
	printf("\n");
	return (0);
}
