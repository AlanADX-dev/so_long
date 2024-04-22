/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:19:51 by aandrieu          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:53 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, int *len)
{
	write (1, &c, 1);
	*len += 1;
}

void	ft_string(char *str, int *len)
{
	if (!str)
	{
		ft_string("(null)", len);
		return ;
	}
	while (*str)
	{
		ft_char(*str, len);
		str++;
	}
}
