#include "main.h"
/**
 * _strcpy - this copies the string pointed to by source
 * @arr: to copy destination
 * @dep: to copy source
 * Return: string
 */
char *_strcpy(char *dep, char *arr)
{
int i = 0;
int j = 0;
while (*(dep + 1) != '\0')
{
i++;
}
for ( ; j < i ; j++)
{
arr[j] = dep[j];
}
arr[i] = '\0';
return (arr);
}

/**
 * _strcat - adjusts the source string to the destination string
 * @dep: the source string
 * @arr: the destination string
 * Return: arr
 */
char *_strcat(char *arr, char *dep)
{
int arrlen = 0;
int deplen = 0;
int i;
for (i = 0 ; arr[i] != '\0' ; i++)
arrlen++;
for (i = 0 ; dep[i] != '\0' ; i++)
deplen++;
for (i = 0 ; i <= deplen ; i++)
arr[arrlen + i] = dep[i];
return (arr);
}

/**
 * _strcmp - function for two string value comparism
 * @str1: first string to be compared
 * @str2: second string to be compared
 * Return: str1[i] - str2[i]
 */
int _strcmp(char *str1, char *str2)
{
int j;
j = 0;
while (str1[j] != '\0' && str2[j] != '\0')
{
if (str1[j] != str2[j])
{
return (str1[j] - str2[j]);
}
j++;
}
return (0);
}
/**
 * _strncat - function that links two strings
 * @A: the source of the string
 * @B: the destination of the string
 * @num: number of bytes to link
 * Return: B
 */
char *_strncat(char *A, char *B, int num)
{
int x;
int y;
x = 0;
while (B[x] != '\0')
{
x++;
}
y = 0;
while (y < num && A[y] != '\0')
{
B[x] = A[y];
x++;
y++;
}
B[x] = '\0';
return (B);
}
/**
*_strncmp - for comparism of strings
*@s1: string one
*@s2: string two
*@c: sums number of characters
*Return: always 0
*/
size_t _strncmp(char *s1, char *s2, size_t c)
{
size_t a, b;
for (b = 0; s1[b] != '\0' && b < c; b++)
{
a = s1[b] - s2[b];
if (a != 0)
{
return (a);
}
}
return (0);
}
