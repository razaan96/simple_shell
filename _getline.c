#include "main.h"
/**
 * _getline - function reads the input of user
 *
 * Return: returns a string
 */
char *_getline(void)
{
char *p = NULL;
size_t command = 0;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
if (getline(&p, &command, stdin) == -1)
{
free(p);
return (NULL);
}
return (p);
}
