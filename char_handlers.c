#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * _strlen - calculate the length of a string
 * @s: string
 * Return: the length of a string
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _atoi - converts the string argument str to an integer
 * @s:string
 * Return:int
 */
int _atoi(char *s)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _puts - writes a string to stdout up to but not including
 * the null character.
 * @str:pointer char
 * return:void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
_putchar('\n');
return;
}
