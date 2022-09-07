#include "shell.h"

/**
 * command_hist - prints the history of the process commands of the shell
 * @c:parsed command
 * @s:status of the last execute
 * Return: 0 Succes -1 Fail
 */
int command_hist(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".simple_shell_hist";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		writer(er);
		free(er);
		writer(" ");
		writer(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
 * normal_echo - Excute Normal Echo
 * @cmd: parsed command
 * Return: 0 Succes -1 Fail
 */
int normal_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
