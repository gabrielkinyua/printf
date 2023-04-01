#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: no. of characters printed (excluding the null byte used)
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	va_start(args, format);
	if (!format)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
				print_char(args, &count);
			else if (format[i] == 's')
				print_string(args, &count);
			else if (format[i] == '%')
				print_percent(&count);
			else if (format[i] == 'd')
				count += print_i_and_d(args);
			else if (format[i] == 'i')
				count += print_i_and_d(args);
			else
			{
				count += write(1, &format[i - 1], 1);
				count += write(1, &format[i], 1);
			}
		}
		else
		{
			if (format[i] == '%')
				return (-1);
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
