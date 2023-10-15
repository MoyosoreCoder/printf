#include <unistd.h>
/**
 * _putchar - a fuction that writes a character to stdout
 * @c: the character to write
 *
 * Return: on success, the number of character written
 * On error, -1 is returrned, errno is set appropriately
 */
int _putchar(char c)
{
	return (write (1, &c, 1));
}	
