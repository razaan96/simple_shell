#include "main.h"
/**
 * _strlen - a function to return length of string
 * @s: character of string
 * Return: always (0)
 */
int _strlen(char *s)
{
	int total_len;

	total_len = 0;
	while (s[total_len] != '\0')
	{
		total_len++;
	}
	return (total_len);
}
