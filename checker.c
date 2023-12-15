#include "shell.h"
/**
 *checker_v- check if its a builtin function
 *@cmd: token user input
 *@buf: line fromgetline function
 *Return: 1 excuted 0 not executed
 */
int checker_v(char **cmd, char *buf)
{
	if (builtin_fun(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
