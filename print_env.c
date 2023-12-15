#include "shell.h"

/**
* draw_env - prints environment str to stdout
*
* Return: 0
*/
void draw_env(void)
{
	int y = 0;
	char **env = environ;

	while (env[y])
	{
		write(STDOUT_FILENO, (const void *)env[y], _strlen(env[y]));
		write(STDOUT_FILENO, "\n", 1);
		y++;
	}
}
