#include "main.h"

/**
 * flags - A function that selects the appropriate function for the format
 * specifier passed to it, and passes the va_list to the appropriate function.
 *
 * @args: A va_list containing the list of arguments passed to _printf.
 * @s: The format specifier character.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void flags(va_list args, const char s, int *len)
{
	if (s == 'd' || s == 'i')
		_printf_decimal(va_arg(args, int), len);
	else if (s == 'u')
		_printf_unsigned_int(va_arg(args, unsigned int), len);
	else if (s == 'c')
		_printf_char((char)va_arg(args, int), len);
	else if (s == 's')
		_printf_string(va_arg(args, char *), len);
	else if (s == '%')
		_printf_char(s, len);
	else if (s == 'x' || s == 'X')
		_printf_hexa(va_arg(args, int), s, len);
	else if (s == 'p')
		_printf_adress(va_arg(args, void *), len);
}

/**
 * _printf - A function that prints a formatted string to the standard output.
 *
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len;

	len = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags(args, *format, &len);
		}
		else
			_printf_char(*format, &len);
		format++;
	}

	va_end(args);
	return (len);
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}