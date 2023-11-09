#include "main.h"
#include <limits.h>
/**
*is_digit -this function specifies if a given string contains digits
*pt: prints a given string
*Return: always 0
*/
int is_digit(const char *prt)
{
unsigned int j;
for (j = 0; prt[j]; j++)
{
if (prt[j] < 48 || prt[j] > 57)
return (0);
}
return (1);
}
/**
*exit_cmds - this function that exits simple shell
*@av: the name of the programme
*@ptr: pointer to a character
*@_exit: exit cmd
*@args: the argument given
*Return: always return void
*/
void exit_cmds(char *av, char **args, char *ptr, int _exit)
{
int exit_stat = 0, digit, len, num;
if (!args[1])
{
free(ptr);
free(args);
exit(_exit);
}
exit_stat = atoi(args[1]);
digit = is_digit(args[1]);
len = _strlen(args[1]);
num = exit_stat > INT_MAX;
if (!digit || len > 10 || num)
{
fprintf(stderr, "%s: 1: %s: Illegal number: %s\n", av, args[0], args[1]);
free(ptr);
free(args);
exit(2);
}
free(ptr);
free(args);
exit(exit_stat % 256);
}
/**
*_getenviron - a function that gets the environment variables
*@env : contains environment variables
*Return : always 0
*/
void _getenviron(char **env)
{
size_t i = 0;
while (env[i])
{
write(STDOUT_FILENO, env[i], _strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}
/**
*_getpath - this function gets the PATH of a given variable
*@environ: contains environment variables
*Return: return path
*/
char *_getpath(char **environ)
{
size_t var, i, c;
char *path = NULL;
for (i = 0; _strcmp(environ[i], "PATH")i = 0;)
{};
if (environ[i] == NULL)
return (NULL);
for (c = 5; environ[i][var]; var++, c++)
{};
path = malloc(sizeof(char) * (c + 1));
if (path == NULL)
return (NULL);
for (var = 5, c = 0; environ[i][var]; var++, c++)
path[c] = environ[i][var];
path[c] = '\0';
return (path);
}
