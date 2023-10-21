#include "main.h
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
 * Return: the number of characters printed
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
				case 'd':
				case 'i':
					ch_count += print_intg(options);
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
