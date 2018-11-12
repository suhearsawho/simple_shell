#include "shell.h"

void print_ps1(void)
{
	char ps1[] = "$ ";
	size_t len_ps1;

	len_ps1 = _strlen(ps1);
	write(STDOUT_FILENO, ps1, len_ps1);
}
