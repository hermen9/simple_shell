#include "shell.h"

/**
* trypath - checks if path is valid
* @pth: tokenized path
* @cmd: user entered command
*
* Return: path 
*/
char *trypath(char **pth, char *cmd)
{
	int a = 0;
	char *output;

	while (pth[a])
	{
		output = fix_path(pth[a], cmd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		a++;
	}
	return (NULL);
}
