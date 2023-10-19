#include "main.h"
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
 * process_specifiers - this process the specifiers individually
 * @format: the formatted specifier
 * @options: the arguments in a va_list
 * Return: the function that prints each format specifier
*/
int process_specifiers(const char *format, va_list options)
{
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
 * print_percent - prints percent specifier
 *
 * Return: the charcter
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
		if (*format  == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			ch_count = process_specifiers(format, options);
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
