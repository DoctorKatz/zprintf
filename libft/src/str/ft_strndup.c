/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:48:55 by null              #+#    #+#             */
/*   Updated: 2020/02/25 17:48:55 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int size)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	len = ft_strlen(s);
	if (size < len)
		str = ft_strnew(size);
	else
		str = ft_strnew(len);
	while (s[i] && i < size)
	{
		str[i] = s[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}