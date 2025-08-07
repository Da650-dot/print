#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_uns(unsigned int n);
int		ft_print_ptr(unsigned long ptr);
int	ft_print_hex(unsigned long n, char format);

#endif