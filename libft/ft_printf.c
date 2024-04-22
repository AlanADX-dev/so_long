/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:19:24 by aandrieu          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:27 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(char s, va_list args, int *i, int *len)
{
	if (s == 'c')
		ft_char(va_arg(args, int), len);
	else if (s == 's')
		ft_string(va_arg(args, char *), len);
	else if (s == 'p')
		ft_pointer((size_t)va_arg(args, size_t *), len);
	else if (s == 'd' || s == 'i')
		ft_int(va_arg(args, int), len);
	else if (s == 'u')
		ft_unsigned(va_arg(args, unsigned int), len);
	else if (s == 'x' || s == 'X')
		ft_hexa(va_arg(args, unsigned int), s, len);
	else if (s == '%')
		ft_char('%', len);
	else
	{
		(*i)--;
		(*len)++;
		ft_char('%', len);
		ft_char(s, len);
	}
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_check(str[i], args, &i, &len);
			i++;
		}
		else
		{
			ft_char(str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
