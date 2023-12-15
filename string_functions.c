#include "shell.h"

/**
* strcmp - compares 2 strings
* @sc1: compared to s2;
* @sc2: compared to s1;
*
* Return: returns result
*/
int strcmp(char *sc1, char *sc2)
{
	int x = 0, res;

	while (*(sc1 + x) == *(sc2 + x) && *(sc1 + x) != '\0')
		x++;

	res = (*(sc1 + x) - *(sc2 + x));

	return (res);
}

/**
* strlen - returns  length of string
* @str: string passed
*
* Return: length of string
*/
int strlen(char *str)
{
	int cnt = 0;

	while (*str != '\0')
	{
		cnt++;
		str++;
	}
	return (cnt);
}

/**
* strncmp - compares two strings up to n bytes
* @sc1: compared to s2
* @sc2: compared to s1
* @nb: number of bytes
*
* Return: res between s1 and s2
*/
int strncmp(char *sc1, char *sc2, int nb)
{
	int x;

	for (x = 0; sc1[x] && sc2[x] && x < nb; x++)
	{
		if (sc1[x] != sc2[x])
			return (sc1[x] - sc2[x]);
	}
	return (0);
}

/**
* strdup - duplicates string
* @str: duplicated strng
*
* Return: pointer to string
*/
char *strdup(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		ptr[i] = str[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* strchar - locate char in a string
* @str: string to be checked
* @c: character to be located
*
* Return: pointer to first occurence of character
*/
char *strchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (!c)
		return (str);
	return (NULL);
}
