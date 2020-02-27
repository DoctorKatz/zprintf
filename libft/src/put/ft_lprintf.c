/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:17:49 by null              #+#    #+#             */
/*   Updated: 2020/02/27 17:03:16 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*check_flags(int d, char *s, char *c, va_list factor)
{
	char	**st;

	c++;
	if (*c == 'd')
	{
		d = va_arg(factor, int);
		ft_putnbr(d);
	}
	else if (*c == 's')
	{
		s = va_arg(factor, char *);
		ft_putstr(s);
	}
	else if (*c == 'u')
	{
		d = va_arg(factor, unsigned long);
		ft_putnbr((int)d);
	}
	return (c);
}

void				ft_lprintf(char *format, ...)
{
	int				d;
	unsigned long	u;
	char			*s;
	char			*c;
	va_list			factor;

	va_start(factor, format);
	c = format;
	while (*c)
	{
		if (*c != '%')
		{
			ft_putchar(*c);
			c++;
			continue;
		}
		c = check_flags(d, s, c, factor);
		c++;
	}
	va_end(factor);
}

void				print_table(int d, char *str)
{
	int	temp;

	temp = d - ft_strlen(str);
	while (--temp)
		ft_putchar(' ');
	ft_putstr(str);
}

char				*zcheck_flags(int d, char *s, char *c, va_list factor)
{
	char	*temp;

	c++;
	if (*c == 'd')
	{
		d = va_arg(factor, int);
		temp = ft_itoa(d);
		return (temp);
	}
	else if (*c == 's')
	{
		s = va_arg(factor, char *);
		return (s);
	}
	return (c);
}

char				*fuck_norminete(char *c)
{
	static char	str[256];
	int			i;


		str[i] = (*c);
		i++;
		return (str);
}

char				*ft_zlprintf(char *format, ...)
{
	int			d;
	static char	s[256];
	char		*c;
	va_list		factor;
	char		*str;

	va_start(factor, format);
	c = format;
	ft_strclr(s);
	while (*c)
	{
		if (*c != '%')
		{
			str = fuck_norminete(c);
			c++;
			continue;
		}
		ft_strcat(s, zcheck_flags(d, s, c, factor));
		c += 2;
	}
	va_end(factor);
	ft_strcat(s, str);
	//free(str);
	return (s);
}
