#include "main.h"
/**
*_strchar - locates C first appearance
*@ch: characters to the string
*@str: receives string
*Return: returns a pointer
*/
char *_strchar(const char *str, int ch)
{
while (*str != (char)ch)
if (!*str++)
return (0);
return ((char *)str);
}
/**
*_strsp - finds the maximum length of a string
*@str1: a string to find the maximum length
*@str2: a string containing the delimiters
*Return: length
*/
size_t _strsp(const char *str1, const char *str2)
{
size_t t = 0;
while (*str1 && _strchar(str2, *str1++))
t++;
return (t);
}
/**
*_strcsp - calculates the length or  maximum length of a string or arguments
*@str1: a string to find its maximum length
*@str2: a string for used comparism
*Return: to length
*/
size_t _strcsp(const char *str1, const char *str2)
{
size_t t = 0;
while (*str1)
{
if (_strchar(str2, *str1))
return (t);
str1++;
t++;
}
return (t);
}

/**
*_strtok - the function that tokenizes strings
*@str: string to be tokenized
*@delimiter: characters to be utilized for strings tokenization
*Return: the tokenized string
*
*/
char *_strtok(char *str, const char *delimiter)
{
static char *j;
if (str)
j = str;
else if (!j)
return (0);
str = j + _strsp(j, delimiter);
j = str + _strcsp(str, delimiter);
if (j == str)
return (j = 0);
j = *j ? *j = 0, j + 1 : 0;
return (str);
}
/**
*_strlen - length of a string
*@str: the string to be returned
*Return: strings length
*/
int _strlen(char *str)
{
int u;
int number = 0;
for (u = 0; str[u] != '\0'; u++)
number++;
return (number);
}
