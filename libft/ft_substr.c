/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:03:14 by aandrieu          #+#    #+#             */
/*   Updated: 2023/02/21 21:22:00 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;

	i = 0;
	l = ft_strlen(s) - start;
	if (len == 0 || start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	if (len < l)
		l = len;
	str = malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
