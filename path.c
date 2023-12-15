#include "shell.h"

/**
* venue - locates the path 4rm global variable
* Return: nothing if path unavailable
*/
char *venue(void)
{
	int xa;
	char **envi = environ, *path = NULL;

	while (*envi)
	{
		if (_strncmp(*envi, "PATH=", 5) == 0)
		{
			path = *envi;
			while (*path && xa < 5)
			{
				path++;
				xa++;
			}
			return (path);
		}
		envi++;
	}
	return (NULL);
}
