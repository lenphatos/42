/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:11:33 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/07 11:08:53 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, len(s));
	write(fd, "\n", 1);
}
