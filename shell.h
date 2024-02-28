#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
extern char **environ;
char *read_string(void);
void string_tok(char *input_string, char *delim, char ***argv);
int _strlen(char *s);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void execute(char *argv[]);
char *get_locate(char *cmd);
void exit_shell(void);
void env_shell(void);
char *_getenv(const char *name);
void non_interactive(char *argv[], char *delim, char *input_string);
void _error_output(char *argv[]);

#endif
