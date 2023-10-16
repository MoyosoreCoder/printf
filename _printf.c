#include "main.h"

/**
 * _printf - this is a function that formatted string
 * @format: a format string containing format specifier
 *
 * Return: The number of charcaters printed
 */
int _printf(const char *format, ...)
{
	va_list options;
	int count = 0;

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
					char_count += print_char(args);
					break;
				case 's':
					char_count += print_string(args);
					break;
				case '%':
					char_count += print_percent();
					break;
				default:
					_putchar('%');
					_putchar(*format);
					char_count += 2;
			}
		}
		else
		{
			char_count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return char_count;

/**
 * print_ch - prints a chaarcter
 * @options: a va_list containing charcter to print
 *
 * Return: the number of characters to ptint
 */

/**
 * print_str -  a function that prints a string
 * @options: a va_list containing strings to print
 *
 * Return: the number of character
 */
