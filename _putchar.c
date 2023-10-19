#include "main.h"
/**
 * _putchar - writes a charcter to standard output
 * @c: the character to print
 *
 * Return: on success 1 is returned, on error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
