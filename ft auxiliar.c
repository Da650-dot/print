#include "ft_printf.h"  // Inclui o cabeçalho com os protótipos e includes padrão

// Função que imprime um caractere e retorna 1 (quantidade de caracteres impressos)
int	print_char(char c)
{
	write(1, &c, 1);    // Escreve o caractere no stdout (fd 1)
	return (1);         // Retorna 1 porque apenas um caractere foi impresso
}

// Função que imprime uma string e retorna o número de caracteres impressos
int	print_str(const char *s)
{
	int	count;

	if (!s)                      // Se o ponteiro da string for NULL
		return (print_str("(null)")); // Imprime "(null)" e retorna o número de caracteres

	count = 0;
	while (s[count])            // Percorre a string até o caractere nulo
		print_char(s[count++]); // Imprime cada caractere usando print_char
	return (count);             // Retorna a quantidade total de caracteres impressos
}

// Função que imprime um número inteiro com sinal e retorna a quantidade de caracteres
int	print_nbr(int n)
{
	long	nb;         // Usa long para evitar overflow com o valor mínimo de int
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)                // Se o número for negativo
	{
		count += print_char('-'); // Imprime o sinal de menos
		nb = -nb;                 // Torna o número positivo
	}
	if (nb >= 10)              // Se ainda houver dígitos à esquerda
		count += print_nbr(nb / 10); // Chama recursivamente para imprimir esses dígitos
	count += print_char((nb % 10) + '0'); // Imprime o último dígito
	return (count);            // Retorna o total de caracteres impressos
}

// Função que imprime um número sem sinal (unsigned int)
int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)                    // Se houver mais de um dígito
		count += print_unsigned(n / 10); // Chama recursivamente para imprimir os dígitos da esquerda
	count += print_char((n % 10) + '0'); // Imprime o dígito da unidade
	return (count);                // Retorna o total de caracteres impressos
}

// Função que imprime um número em hexadecimal (pode ser minúsculo ou maiúsculo)
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

// Função que imprime um ponteiro (endereços de memória) no formato 0xabcdef...
int	print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)                          // Se o ponteiro for NULL
		return (print_str("(nil)"));   // Imprime "(nil)" como o printf original

	count = print_str("0x");           // Prefixo de ponteiros em C
	count += print_hex(ptr, 'x');      // Imprime o valor do ponteiro em hexadecimal minúsculo
	return (count);                    // Retorna a quantidade de caracteres impressos
}
