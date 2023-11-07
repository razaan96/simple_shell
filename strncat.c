#include "main.h"
/**
 * _strncat - appends two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: resulting string
 */

char *_strncat(char *dest, const char *src)
{
	int len1, len2;

	for (len1 = 0; dest[len1] != '\0'; len1++)
	{

	}

	len2 = 0;
	while (src[len2] != '\0')
	{
		dest[len1] = src[len2];
		len1++;
		len2++;
	}

	dest[len1] = '\0';

	return (dest);
}
