/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:29:36 by aandrieu          #+#    #+#             */
/*   Updated: 2023/02/21 19:31:47 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "./ft_printf.h"

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int	ft_strlen(char *s);

#endif
