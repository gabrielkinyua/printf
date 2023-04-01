#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_percent(int *count);
int print_i_and_d(va_list id);

#endif /* MAIN_H */
