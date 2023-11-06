#include "main.h"
/**
*_getline - this reads the user command
*
*Return: returns a string
*/
char *_getline(void)
{
char *ptr = NULL;
size_t cmds = 0;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
if (getline(&ptr, &cmds, stdin) == -1)
{
free(ptr);
return (NULL);
}
return (ptr);
}
