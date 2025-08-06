#include "ft_printf.h"

static int	check_args(const char format, va_list args)
{
	if (format == 'c')
		return ft_print_char(va_arg(args, int));
	if (format == 's')
		return ft_print_string(va_arg(args, char *));
	if (format == 'p')
		return ft_print_ptr(va_arg(args, unsigned long));
	if (format == 'd' || format == 'i')
		return ft_print_number(va_arg(args, int));
	if (format == 'u')
		return ft_print_unumber(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		return (print_hex(va_arg(args, unsigned int), format));
		return ft_print_char('%');
	return 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	if(!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += check_args(format[i + 1], args);
			i++;
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
