/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguunship <lguunship@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:20:47 by lguunship         #+#    #+#             */
/*   Updated: 2020/02/02 20:29:31 by lguunship        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void		strdel(void *str, size_t size)
{
	ft_memdel(&str);
	(void)size;
}

int				ft_getlines(int fd, t_list **lst)
{
	t_list	*ptr;
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		ptr = ft_lstnew(line, ft_strlen(line) + 1);
		ft_strdel(&line);
		if (ptr == NULL)
		{
			ret = -1;
			break ;
		}
		ft_lstadd(lst, ptr);
	}
	if (ret == -1)
	{
		ft_lstdel(lst, strdel);
		return (0);
	}
	ft_lstrev(lst);
	return (1);
}
