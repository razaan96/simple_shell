#include "main.h"
/**
* _getsenv - Get the value of an environment variable
* @var: Name of the environment variable
* Return: Value of the environment variable or NULL
*/
char *_getsenv(char *var)
{
char **environ;
int i, j, len;

for (i = 0; environ[i]; i++)
{
len = _strlen(var);
for (j = 0; j < len && environ[i][j] == var[j]; j++)
if (j == len && environ[i][j] == '=')
return (environ[i] + len + 1);
}
return (NULL);
}
