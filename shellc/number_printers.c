#include "shell.h"
/**
 * unsigned_int_printer - print unsigned integer using _putchar
 * @n: unisigned integer
 * Return: Void
 */
void unsigned_int_printer(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		unsigned_int_printer(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * int_printer - print integer using _putchar
 * @n:integer
 * Return: void
 */
void int_printer(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		unsigned_int_printer(x / 10);

	_putchar(x % 10 + '0');
}
