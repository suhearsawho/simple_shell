#include "shell.h"

int main(void)
{
	printf("getenv: %s\n", _getenv("MAR"));
	_setenv("MAR", "HELLO", 1);
	printf("getenv: %s\n", _getenv("MAR"));
	    
	printf("test 2, adding a new Variable\n");

	printf("getenv: %s\n", _getenv("SU"));
	_setenv("SU", "san", 1);
	printf("getenv: %s\n", _getenv("SU"));
	return (0);
}
