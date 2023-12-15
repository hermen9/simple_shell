#include "shell.h"

/**
* clear_buffers - frees buffers
* @buf: buffer to clear
*
* Return: nill
*/
void clear_buffers(char **buf)
{
	int x = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[x])
	{
		free(buf[x]);
		x++;
	}
	free(buf);
}
