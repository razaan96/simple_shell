#include "main.h"
/**
* getenv - Get the value of an environment variable
* @variable: Name of the environment variable
* Return: Value of the environment variable or {printf(name of var)} or NULL
*/

char *getenv(const char *variable)
{
char **enviro, *aux, *tok, *owo;
int siz;
siz = _strlen((char *) variable);

for (enviro = environ; *enviro; ++enviro)

{
aux = _strdup(*enviro);
tok = strtok(aux, "=");
if (tok == NULL)
{
free(aux);
return (NULL);
}

if (_strlen(tok) != siz)
{
free(aux);
continue;
}
if (_strcmp((char *) variable, aux) == 0)
{
tok = strtok(NULL, "=");
owo = _strdup(tok);
free(aux);
return (owo);
}
free(aux);
}
return (NULL);
}
