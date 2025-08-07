#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_print_char('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_print_nbr(num / 10);
	count += ft_print_char((num % 10) + '0');
	return (count);
}
