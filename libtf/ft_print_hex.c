#include "ft_printf.h"

int	print_hex(unsigned long n, char format)
{
	char	*base;      // Ponteiro para os caracteres hexadecimais
	int		count;

	count = 0;
	if (format == 'x')                 // Se for hexadecimal minúsculo
		base = "0123456789abcdef";
	else                               // Se for hexadecimal maiúsculo ('X')
		base = "0123456789ABCDEF";

	if (n >= 16)                       // Se o número for maior que 15 (tem mais de um dígito)
		count += print_hex(n / 16, format); // Chama recursivamente para os dígitos da esquerda
	count += print_char(base[n % 16]); // Imprime o dígito correspondente no final
	return (count);                    // Retorna a quantidade de caracteres impressos
}
