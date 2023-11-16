#include "main.h"
/**
 * tokenizr - the main program of simple shell
 * Description: to run a simple shell program
 * @line: argument count
 * Return: void
 */
char **tokenizr(char *line)
{
char *tokn = NULL, *tmp = NULL;
char **command = NULL;
int pt = 0, i = 0;
if (!line)
return (NULL);
tmp = _strdup(line);
#define DELIM " \t\n"  /* Example delimiters: space, tab, and newline */
tokn = strtok(tmp, DELIM);
if (tokn == NULL)
{
free(tmp), tmp = NULL;
free(line), line = NULL;
return (NULL);
}
while (tokn)
{
pt++;
tokn = strtok(NULL, DELIM);
}
free(tmp), tmp = NULL;
command = malloc(sizeof(char *) * (pt + 1));
if (!command)
{
free(line), line = NULL;
return (NULL);
}
tokn = strtok(line, DELIM);
while (tokn)
{
command[i] = _strdup(tokn);
tokn = strtok(NULL, DELIM);
i++;
}
free(line), line = NULL;
command[i] = NULL;
return (command);
}
