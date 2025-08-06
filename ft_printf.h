#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_umb(unsigned int n);
int		ft_print_ptr(unsigned long ptr);
int		ft_puthex(unsigned long num);
int		ft_put_upperhex(unsigned long num);

#endif