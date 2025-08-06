#include "ft_printf.h"

int	print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)                                // Se o ponteiro for NULL (0)
		return (print_string("(nil)"));      // Imprime "(nil)", como o printf original

	count = print_string("0x");              // Adiciona o prefixo "0x"
	count += print_hex(ptr, 'x');            // Imprime o valor em hexadecimal minúsculo

	return (count);                          // Retorna o total de caracteres impressos
}
