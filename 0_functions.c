#include <stdio.h>

void print_char(va_list args)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
}

void print_string(va_list args)
{
	int i = 0;
	char *s = va_arg(args, char *);
	for (; str[i] != '\0'; i++)
	{
		write(1, &str[i], i);
	}
}

void print_percent(void)
{
	char c = '%';
	write(1, &c, 1);
}
