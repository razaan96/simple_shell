#include "main.h"
/**
*_strdup - program
*Return:0
*@str:parameter
*/
char *_strdup(const char *str)
{
int leng = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
leng++;
ret = malloc(sizeof(char) * (leng + 1));
if (!ret)
return (NULL);
for (leng++; leng--;)
ret[leng] = *--str;
return (ret);
}
