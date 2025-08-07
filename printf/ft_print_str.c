#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i = 0;

	if (!str)
		return (ft_print_str("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
