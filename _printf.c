#include "main.h"
/**
 * _putchar - a fuction that writes a character to stdout
 * @c: the character to write
 * Return: on success, the number of character written
 * On error, -1 is returrned, errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_ch - function that prints character
 * @options: a va_list containing arguments
 *
 * Return: the number of charcters
 */
int print_ch(va_list options)
{
	char c;
	c = va_arg(options, int);

	return (_putchar(c));
}
/**
 * print_str - a function that prints a string
 * @options: a va_list containing arguments
 *
 * Return: the numbers of characters
 */
int print_str(va_list options)
{
	char *str;

	int ch_count = 0;

	str = va_arg(options, char *);

	while (*str)
	{
		ch_count += _putchar(*str);
		str++;
	}
	return (ch_count);
}
/**
 * print_percent - prints percent
 * Return: the numbers of charcters printed on the screen
 */
int print_percent(void)
{
	return (_putchar('%'));
}
/**
 * _printf - function that prints formatted string
 * @format: arguments containing different format specifier
 * Return: the number of characters printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	int ch_count = 0;

	va_list options;
	va_start(options, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
			{
				break;
			}
			switch (*format)
			{
				case 'c':
					ch_count += print_ch(options);
					break;
				case 's':
					ch_count += print_str(options);
					break;
				case '%':
					ch_count += print_percent();
					break;
				default:
					_putchar('%');
					_putchar(*format);
					ch_count += 2;
			}
		}
		else
		{
			ch_count += _putchar(*format);
		}
		format++;
	}
	va_end(options);
	return (ch_count);
}
