#include "main.h"
/**
 * print_ch - print a character
 * @options: va_list that contain the character
 *
 * Return: the number of characters
 */
int print_ch(va_list options)
{
	char c;

	c = va_arg(options, int);

	return (_putchar(c));
}
/**
 * print_str - prints a string
 * @options: va_list that contain the string
 *
 * Return: number of string
 */
int print_str(va_list options)
{
	int ch_count = 0;

	char *str;

	str = va_arg(options, char *);

	while (*str)
	{
		ch_count += _putchar(*str);
		str++;
	}
	return (ch_count);
}
/**
 * print_percent - a function that prints percent
 *
 * Return: number of characters printed
 */
int print_percent(void)
{
	return (_putchar('%'));
}
/**
 * handle_case - handles format specifier for c, s and %
 * @format: the format specifier in the code
 * @options: the va_list containing array of arguments
 *
 * Return: the numbers of characters printed
 */
int handle_case(const char *format, va_list options)
{
	format++;

	if (*format == '\0')
	{
		return (0);
	}
	switch (*format)
	{
		case 'c':
			return (print_ch(options));
		case 's':
			return (print_str(options));
		case '%':
			return (print_percent());
		default:
			_putchar('%');
			_putchar(*format);
			return (2);
	}
}

/**
 * _printf - this is a function that formatted string
 * @format: a format string containing format specifier
 *
 * Return: The number of charcaters printed
 */
int _printf(const char *format, ...)
{
	va_list options;

	int ch_count = 0;

	va_start(options, format);

	while (*format)
	{
		if (*format == '%')
		{
			ch_count = handle_case(format, options);
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
