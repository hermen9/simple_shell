#include "shell.h"

/**
* kill_cmd - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void kill_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
