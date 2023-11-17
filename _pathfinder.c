#include "main.h"
/**
*pathfind - function finds the "PATH" to environment variables
*@args: arguments
*@environ: function contains variables of the environment
*Return: returns PATH always
*/
int pathfind(char **args, char **environ)
{
char *tok = NULL, *fpath = NULL, *path_t = NULL;
size_t v, cmd;
struct stat stat_ptr;
if (stat(*args, &stat_ptr) == 0)
return (-1);
path_t = _getpath(environ);
if (!path_t)
return (-1);
tok = _strtok(path_t, ":");
cmd = _strlen(*args);
while (tok)
{
v = _strlen(tok);
fpath = malloc(sizeof(char) * (v + cmd + 2));
if (!fpath)
{
*args = fpath;
free(path_t);
return (0);
}
free(fpath);
tok = _strtok(NULL, ":");
}
free(path_t);
return (-1);
}
