/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:19:35 by aandrieu          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:37 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_char(char c, int *len);
void	ft_string(char *args, int *len);
void	ft_int(int nb, int *len);
void	ft_pointer(size_t p, int *len);
void	ft_unsigned(unsigned int u, int *len);
void	ft_hexa(unsigned int h, char minMAJ, int *len);
void	ft_hexap(unsigned long long h, char minMAJ, int *len);

int		ft_printf(char *str, ...);
int		ft_strlen(char *s);

#endif
