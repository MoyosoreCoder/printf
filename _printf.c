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
	int count = 0, i;

	va_start(options, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else
		{
			i++;

			switch (format[i])
			{
				case 'c':
					count += print_ch(options);
					break;
				case 's':
					count += print_str(options);
					break;

				default:
					count += _putchar('%');
					count += _putchar(format[i]);
			}
		}
	}
	va_end(options);
	return (count);
}
/**
 * print_ch - prints a chaarcter
 * @options: a va_list containing charcter to print
 *
 * Return: the number of characters to ptint
 */
int print_ch(va_list options)
{
	char c;

	c = va_arg(options, int);

	return (_putchar(c));
}
/**
 * print_str -  a function that prints a string
 * @options: a va_list containing strings to print
 *
 * Return: the number of characters printed
 */
int print_str(va_list options)
{
	char *str;
	int count = 0;

	str = va_arg(options, char *);

	if (str == NULL)
	{
		return (0);
	}

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}
