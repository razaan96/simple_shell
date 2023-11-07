#include "main.h"
/**
*location - program
*Return:0
*@path:parameter
*@args:argument
*/
char *location(char *path, char *args)
{
char *path_copy, *path_token, *filepath;
char *delim = ":";
path_copy = _strdup(path);
path_token = strtok(path_copy, delim);
filepath = malloc(strlen(args) + strlen(path_token) + 2);
while (path_token != NULL)
{
strcpy(filepath, path_token);
strcat(filepath, "/");
strcat(filepath, args);
_strncat(filepath, "\0");
if (access(filepath, X_OK) == 0)
{
free(path_copy);
return (filepath);
}
path_token = strtok(NULL, delim);
}
free(filepath);
return (NULL);
}
/**
*gets_loc - program
*Return:0
*@arg:argument
*/
char *gets_loc(char *arg)
{
char *path;
path = getenv("PATH");
if (path)
{
path = location(path, arg);
return (path);
}
return (NULL);
}
