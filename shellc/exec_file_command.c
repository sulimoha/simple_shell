#include "shell.h"
/**
 * read_file - read command line argument from file
 * @filename:file name
 * @argv:Pprogram name
 * Return: -1 or  0
 */

void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		parse_file_line(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * parse_file_line - parse a file as a command line argument
 * @line: command line from file
 * @counter:Error Counter
 * @fp:file descriptor
 * @argv: program name
 * Return : void
 */
void parse_file_line(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_input(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			_exiter_file_command(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * _exiter_file_command - exit the shell in a command file
 * @line: input line from a file
 * @cmd: parsed command
 * @fd: file descriptor
 * Return : void
 */
void _exiter_file_command(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}
