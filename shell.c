#include "shell.h"
/**
* main - main entry
* @ac: arg count
* @av: arg vector
* @envp: environment vector
*
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcmd = NULL, *pth = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **cmd = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, control_signal);
	while (1)
	{
		free_buffers(cmd);
		free_buffers(paths);
		free(pathcmd);
		popup();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		cmd = tokenizer(line);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (checker_v(cmd, line))
			continue;
		pth = venue();
		paths = tokenizer(pth);
		pathcmd = try_path(paths, cmd[0]);
		if (!pathcmd)
			perror(av[0]);
		else
			execute(pathcmd, cmd);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
