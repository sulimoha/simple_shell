#include "shell.h"
/**
 * _char_cmp - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int _char_cmp(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - extract tokens from strings
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next tokken or null if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_str;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	token_str = nt;
	if (token_str == NULL)
		return (NULL);
	for (i = 0; token_str[i] != '\0'; i++)
	{
		if (_char_cmp(token_str[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	token_str = nt + i;
	nt = token_str;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (_char_cmp(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (token_str);
}
