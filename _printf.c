#include "main.h"

/**
 *
 *
 */
int _printf(const char *format, ...)
{
	va_list options;
	int count = 0, i, j;

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

int print_ch(va_list options)
{

}

