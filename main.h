

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		_printf(const char *format, ...);
void	_printf_char(char c, int *len);
void	_printf_string(char *s, int *len);
void	_printf_decimal(int n, int *len);
void	_printf_unsigned_int(unsigned int n, int *len);
void	_printf_hexa(unsigned int nbr, char Xx, int *len);
void	_printf_adress(void *addr, int *len);
void	_printf_octal(unsigned int nbr, int *len);
void	_printf_binary(unsigned int num, int *len);
void	_printf_ascii(char *s, int *len);


#endif
