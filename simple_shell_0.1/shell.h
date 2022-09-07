#ifndef _SHELL_H_
#define _SHELL_H_


extern char **environ;


#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define writer(c) (write(STDOUT_FILENO, c, _strlen(c)))


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>






char *_strtok(char *str, const char *tok);
unsigned int _char_cmp(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);


void free_env(char **env);
void *populate_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_cmd_line(char **input, char *line);


void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);


int path_cmd(char **line);
char *_getenv(char *name);
char **parse_input(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_env(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void parse_file_line(char *line, int counter, FILE *fd, char **argv);
void _exiter_file_command(char **cmd, char *line, FILE *fd);


void hashtag_handle(char *buff);
int hist(char *input);
int command_hist(char **cmd, int er);
int _env(char **cmd, int er);
int _cd(char **cmd, int er);
int _help(char **cmd, int er);
int _echo(char **cmd, int er);
void  _exiter(char **cmd, char *input, char **argv, int c);
int normal_echo(char **cmd);

void unsigned_int_printer(unsigned int n);
void int_printer(int n);
void print_error(char *line, int c, char **argv);
void _perr(char **argv, int c, char **cmd);


/**
 * struct bulltin_funcs - struct of the builting functions
 * @command:pointer to command
 * @fun: builtin function to execute
 */

typedef struct bulltin_funcs
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
