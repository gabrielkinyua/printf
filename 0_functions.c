#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * print_char - prints char
 * @args: input value
 * @count: input value
 *
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}
/**
 * print_string - prints stirng
 * @count: input value
 * @args: input value
 *
 */
void print_string(va_list args, int *count)
{
	int i = 0;
	const char *s = (const char *)va_arg(args, char *);

	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return;
	}
	for (; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
		(*count)++;
	}
}
/**
 * print_percent - prints percent
 *@count: input value
 *
 */
void print_percent(int *count)
{
	char c = '%';

	write(1, &c, 1);
	(*count)++;
}
/**
 * print_i_and_d - prints i and d
 * @id: input value
 *
 * Return: string length
 */
int print_i_and_d(va_list id)
{
	char buff[12];
	int count = 0;

	count += sprintf(buff, "%d", va_arg(id, int));

	if (!buff[0])
		return (0);
	return (write(1, buff, strlen(buff)));
}
