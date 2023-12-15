#include "shell.h"

/**
 * execute - executes cmds given by users
 *@cp: cmd
 *@cmd: array of pointers to cmd
 * Return: 0
 */
void execute(char *cnp, char **cmd)
{
	pid_t new_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cnp, cmd, env);
		perror(cnp);
		free(cnp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
