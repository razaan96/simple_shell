#include "main.h"
/**
*_fork - this forks processes
*@args: arguments
*@av: arguments of variables
*@ptr: user's command
*@environ: contains environment variables
*@id: function processes identification
*@c: add test
*Return: returns 0 on success
*/
int _fork(char **args, char **av, char **environ, char *ptr, int id, int c)
{
pid_t child;
int status;
char *format = "%s: %d: %s: not found\n";
child = fork();
if (child == 0)
{
if (execve(args[0], args, environ) == -1)
{
fprintf(stderr, format, av[0], id, args[0]);
if (!c)
free(args[0]);
free(args);
free(ptr);
exit(127);
}
}
else
{
wait(&status);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
return (WEXITSTATUS(status));
}
return (0);
}
