#include "ft_printf.h"

int	ft_print_unumber(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unumber(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}
