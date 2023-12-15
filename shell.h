#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker_v(char **cmd, char *buf);
void popup_user(void);
void control_signal(int m);
char **tokenizer(char *line);
char *try_path(char **pth, char *cmd);
char *fix_path(char *pth, char *cmd);
int builtin_fun(char **cmd, char *line);
void kill_cmd(char **command, char *line);

void draw_env(void);

/* string handlers */
int strcmp(char *sc1, char *sc2);
int strlen(char *str);
int strncmp(char *sc1, char *sc2, int nb);
char *strdup(char *str);
char *strchr(char *str, char c);

void execute(char *cnp, char **cmd);
char *venue(void);

/* helper function for efficient free */
void clear_buffers(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */
