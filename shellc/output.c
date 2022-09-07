#include "shell.h"
/**
 *  _perr - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void _perr(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	writer(argv[0]);
	writer(": ");
	writer(er);
	writer(": ");
	writer(cmd[0]);
	writer(": Illegal number: ");
	writer(cmd[1]);
	writer("\n");
	free(er);
}
