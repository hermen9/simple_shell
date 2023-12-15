#include "shell.h"

/**
* builtin_fun - handles exec of builtin functions
* @cmd: tokenized commands
* @line: input read from stdin
*
* Return: 1 executed, 0 no exec
*/
int builtin_fun(char **cmd, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (strcmp(*cmd, builtin.env) == 0)
	{
		draw_env();
		return (1);
	}
	else if (strcmp(*cmd, builtin.exit) == 0)
	{
		kill_cmd(cmd, line);
		return (1);
	}
	return (0);
}
