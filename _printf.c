#include "main.h"
<<<<<<< HEAD
#include <starg.h>
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

	for (i = 0; format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					char c = va_arg(args, int);

					write(1, &c, 1);
					count++;
					break;
				}
				case 's'
				{
					char *s = va_arg(args, char *);

					for (j = 0; s[j] != '\0'; j++)
					{
						write(1, &s[j], 1);
						count++;
					}
					break;
				}
				case '%':
				{
					write(1, "%", 1);
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
=======
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 * by Boss
 */
int _printf(const char *format, ...)

{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buff_ind = 0;

va_list list;

char buffer[BUFF_SIZE];

if (format == NULL)

return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)

{

if (format[i] != '%')

{

buffer[buff_ind++] = format[i];

if (buff_ind == BUFF_SIZE)

print_buffer(buffer, &buff_ind);

/* write(1, &format[i], 1);*/

printed_chars++;

}

else

{

print_buffer(buffer, &buff_ind);

flags = get_flags(format, &i);

width = get_width(format, &i, list);

precision = get_precision(format, &i, list);

size = get_size(format, &i);

++i;

printed = handle_print(format, &i, list, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



print_buffer(buffer, &buff_ind);



va_end(list);



return (printed_chars);

}



/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{

if (*buff_ind > 0)

write(1, &buffer[0], *buff_ind);



*buff_ind = 0;

>>>>>>> f34c0989a48393e12e470eb75dc97a03a1c95e6d
}
