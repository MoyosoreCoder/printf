#include "main.h"
int print_ch(va_list options)
{
	char c;
	c = va_arg(options, int);

	return _putchar(c);
}

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
	return ch_count;
}

int print_percent(void)
{
	return _putchar('%');
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
	return ((ch_count));
}
