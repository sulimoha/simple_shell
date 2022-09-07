#include "shell.h"
/**
 * _exiter - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: input
 * @argv: program name
 * @c:Excute Count
 * Return: void
 */
void  _exiter(char **cmd, char *input, char **argv, int c)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_perr(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}

/**
 * _cd - Changes the current directory of the process
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int _cd(char **cmd, __attribute__((unused)) int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * _env - prints the current environment
 * @cmd:parsed Command
 * @er:Status of last command excuted
 * Return:Always 0
 */
int _env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * _help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int _help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * _echo - Handle variables replacement
 * @st:Status of last executed command
 * @cmd: parsed command
 * Return: always 0 Or execute normal echo
 */
int _echo(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		int_printer(st);
		writer("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		unsigned_int_printer(pid);
		writer("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		writer(path);
		writer("\n");
		free(path);

	}
	else
		return (normal_echo(cmd));

	return (1);
}
