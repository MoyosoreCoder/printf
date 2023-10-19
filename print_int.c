#include
#include ""

int _putchar(char c)
{
	return write(1, &c, 1);
}

int print_intg(va_list options)
{
	int num = va_arg(options, int);
	int char_count = 0;

	if (num < 0)
	{
		_putchar('_');
		char_count++;
		num = -num;
	}

	char digits [10];
	int i = 0;

	if (num == 0)
	{
		char_count += _putchar('0');
	}
	else
	{
		while (num > 0)
		{
			digits[i] = '0' + (num % 10);
			num /= 10;
			i++;
		}
		while (i > 0)
		{
			char_count += _putchar(digits[i - 1])
				i--;
		}
	}

	return char_count;
}

int _printf(const char *format, ...)
{
	va_list options;
	va_start(options, format);

	int char_count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
