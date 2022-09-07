#include "shell.h"

/**
 * main - simple shell (hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		hist(input);
		cmd = parse_input(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			_exiter(cmd, input, argv, counter);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free_cmd_line(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, counter, argv);

		}
		free_cmd_line(cmd, input);
	}
	return (statue);
}
/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"hist", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * creat_env - Creat array of eviroment variables
 * @envi: array of enviroment variable
 * Return: Void
 */
void creat_env(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
