#include "shell.h"

#define BUFSIZE 1024;
int main(void)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t read;
	
    while (1)
    {
    dprintf(1,"$ ");
    read = _getline(&line, &size , stdout);
    if (read == -1)
        break;
    else if (read > 0)
        dprintf(1, "%s\n",line);
    }
    free(line);
    return (0);
}


