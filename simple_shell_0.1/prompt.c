#include "shell.h"

/**
 *prompt - display a prompt and wait for the user to type a command.
 */
void prompt(void)
{
	/* writer("$ "); */
	writer("#cisfun$ ");
}
/**
 * print_error - If an executable cannot be found, print an error message.
 * @input:user input
 * @counter:simple shell count loop
 * @argv:program name
 * Return: void
 */
/* void print_error(char *input, int counter, char **argv)
{
	char *_error;

	writer(argv[0]);
	writer(": ");
	_error = _itoa(counter);
	writer(_error);
	free(_error);
	writer(": ");
	writer(input);
	writer(": not found\n");
} */
void print_error(char *input, int counter, char **argv)
{
	char *_error;

	(void) input;
	(void) counter;
	(void) _error;
	writer(argv[0]);
	writer(": No such file or directory\n");
}
