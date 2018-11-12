#include <stdio.h>
#include <unistd.h>
int main()
{
	char buff[10];
	ssize_t n;
	int i;

	i = n = 0;
	
	write(1,"$ ", 2);
		while ((n = read(0, buff, 10)) > 0)
		{
			i = 0;
			if (n > 1)
			{
				printf("%s", buff);
			}
			else if (n == 1)
				dprintf(1, "%d$ ", (int)n);
		}
	write(1 , "done\n", 5 );
	return 0;
}
