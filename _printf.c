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
	int i, j;
	int count = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0';)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					print_char(args);
					count++;
					break;
				}
				case 's':
				{
						print_string(args);
						count++;
					}
					break;
				}
				case '%':
				{
					print_percent()
					count++;
					break;
				}
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
