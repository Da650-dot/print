#include "ft_printf.h"

int	print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (print_str("(nil)"));

	count = ft_print_str("0x");
	count += ft_print_hex(ptr, 'x');

	return (count);
}
