#include "shell.h"

/**
 * parse_input - parse the input line into a list of arguments
 * @input:input to be parsed
 * Return: arrayof arguments
 */
/* char **parse_input(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
} */
char **parse_input(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	(void) i;
	(void) token;
	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	/* token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	} */
	tokens[0] = input;
	tokens[1] = NULL;
	printf("%s\n", input);
	/* tokens[i] = NULL; */

	return (tokens);
}