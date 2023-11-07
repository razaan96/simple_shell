#include "main.h"
/**
 * _getspath - the main program of simple shell
 * Description: to run a simple shell program
 * @command: argument value
 * Return: void
 */
char *_getspath(char *command)
{
char *pathenv, *fullcmd, *dirs;
int i;
struct stat st;
for  (i = 0; command[i]; i++)
{
if (command[i] == '/')

{
if (stat(command, &st) == 0)
return (_strdup(command));
return (NULL);
}
}
pathenv = _getsenv("PATH");
if (!pathenv)
return (NULL);
dirs = strtok(pathenv, ":");
while (dirs)
{
fullcmd = malloc(_strlen(dirs) + _strlen(command));
if (fullcmd)
{
_strcpy(fullcmd, dirs);
_strncat(fullcmd, "/");
_strncat(fullcmd, command);
if (stat(fullcmd, &st) == 0)
{
free(pathenv);
return (fullcmd);
}
free(fullcmd), fullcmd = NULL;
dirs = strtok(NULL, ":");
}
}
free(pathenv);
return (NULL);
}
