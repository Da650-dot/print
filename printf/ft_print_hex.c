#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";

	if (n >= 16)
		count += ft_print_hex(n / 16, format);
	count += ft_print_char(base[n % 16]);
	return (count);
}
