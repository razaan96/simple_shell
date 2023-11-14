#include "main.h"
/**
 * pathfind - find the full path of a command in "PATH" directories
 * @args: Array of command-line arguments
 * @environ: Pointer to an array of environment variables
 * Return: Full path of the command or void
 */
int pathfind(char **args, char **environ)
{
    char *pathenv, *fullcmd, *dirs;
    int i;
    struct stat st;
    (void)args;

    for (i = 0; environ[i]; i++)
    {
        if (strchr(environ[i], '/') != NULL)
        {
            if (stat(environ[i], &st) == 0)
                return (uintptr_t) _strdup(environ[i]);
            return (0);
        }
    }

    pathenv = _getsenv("PATH");
    if (!pathenv)
        return (0);

    dirs = strdup(pathenv);
    if (!dirs)
    {
        free(pathenv);
        return (0);
    }

    fullcmd = malloc(_strlen(environ[0]) + 2);
    if (!fullcmd)
    {
        free(pathenv);
        free(dirs);
        return (0);
    }

    dirs = strtok(dirs, ":");
    while (dirs)
    {
        _strcpy(fullcmd, dirs);
        _strncat(fullcmd, "/");
        _strncat(fullcmd, environ[0]);

        if (stat(fullcmd, &st) == 0)
        {
            free(pathenv);
            free(dirs);
            return (0);
        }

        dirs = strtok(NULL, ":");
    }

    free(pathenv);
    free(dirs);
    free(fullcmd);
    return (0);
}
