#include "shell.h"

/**
 **_realloc -  changes the size of the memory block
 * pointed to by ptr to size bytes
 *@ptr: pointer
 *@old_size: previous size of the memory block
 *@new_size: new size of the memory block
 *Return: void a pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		populate_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}
/**
 * free_cmd_line - deallocates the memory previously
 * allocated to command and line
 * @cmd: command pointer
 * @line:line pointer
 * Return: Void
 */
void free_cmd_line(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copies n characters from memory area src to memory area dest.
 * @dest: destination pointer
 * @src: source pointer
 * @n: This is the number of bytes to be copied.
 *Return: Void Pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * populate_array - populate an array with const byte
 * @a:void pointer
 * @el: int
 * @len:lenght
 *Return: void pointer
 */
void *populate_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc -  allocates the requested memory
 * @size: size
 * Return: void pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
