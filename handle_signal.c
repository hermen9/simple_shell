#include "shell.h"

/**
 *control_signal- it tracks interactive mode
 *@m: the signal num
 *Return: 0
 */

void control_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
