#include "shell.h"

/**
* fix_path - adds path to command
* @pth: path of command
* @cmd: user entered command
*
* Return: buffer
*/
char *fix_path(char *pth, char *cmd)
{
	char *buf;
	size_t a = 0, b = 0;

	if (cmd == 0)
		cmd = "";

	if (pth == 0)
		pth = "";

	buf = malloc(sizeof(char) * (strlen(pth) + strlen(cmd) + 2));
	if (!buf)
		return (NULL);

	while (pth[a])
	{
		buf[a] = pth[a];
		a++;
	}

	if (pth[a - 1] != '/')
	{
		buf[a] = '/';
		a++;
	}
	while (cmd[b])
	{
		buf[a + b] = cmd[b];
		b++;
	}
	buf[a + b] = '\0';
	return (buf);
}
