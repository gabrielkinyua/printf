#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
void print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
}

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

void print_percent(void)
{
	char c = '%';

	write(1, &c, 1);
}
