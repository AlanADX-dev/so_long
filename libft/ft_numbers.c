/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:18:58 by aandrieu          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:14 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int(int n, int *len)
{
	if (n == -2147483648)
		ft_string("-2147483648", len);
	if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		ft_char('-', len);
	}
	if (n >= 10)
	{
		ft_int(n / 10, len);
		ft_int(n % 10, len);
	}
	if (n >= 0 && n < 10)
		ft_char(n + '0', len);
}

void	ft_pointer(size_t nb, int *len)
{
	if (nb == 0)
		ft_string("(nil)", len);
	else
	{
		ft_string("0x", len);
		ft_hexap(nb, 'x', len);
	}
}

void	ft_unsigned(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned(u / 10, len);
	ft_char(u % 10 + '0', len);
}

void	ft_hexa(unsigned int h, char minMAJ, int *len)
{
	char	*base;

	if (minMAJ == 'x')
		base = "0123456789abcdef";
	if (minMAJ == 'X')
		base = "0123456789ABCDEF";
	if (h >= 16)
		ft_hexa(h / 16, minMAJ, len);
	ft_char(base[h % 16], len);
}

void	ft_hexap(unsigned long long h, char minMAJ, int *len)
{
	char	*base;

	if (minMAJ == 'x')
		base = "0123456789abcdef";
	if (minMAJ == 'X')
		base = "0123456789ABCDEF";
	if (h >= 16)
		ft_hexap(h / 16, minMAJ, len);
	ft_char(base[h % 16], len);
}
