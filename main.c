#include "main.h"
/**
*main - main function of the shell
*@av: function holds array strings
*@environ: function has the environment variable
*@ac: checks the total arguments in a given variable
*Return: this function returns 0 on success
 */
int main(int ac, char **av, char **environ)
{
char *cmds = NULL, **usercmd = NULL;
int p = 0, _exit = 0, u = 0;
(void)ac;
while (1)
{
cmds = _getline();
if (cmds == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(_exit);
}
p++;
usercmd = tokenizr(cmds);
if (usercmd == NULL)
{
free(cmds);
continue;
}
if (_strcmp(usercmd[0], "exit") == 0)
{
exit_cmds(av[0], usercmd, cmds, _exit);
}
else if (_strcmp(usercmd[0], "env") == 0)
{
_getenviron(environ);
}
else
{
_exit = _fork(usercmd, av, environ, cmds, p, u);
if (u == 0)
free(usercmd[0]);
}
free(usercmd);
free(cmds);
}
return (_exit);
}
