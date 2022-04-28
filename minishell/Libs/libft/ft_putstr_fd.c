/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:51:02 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/08 18:38:06 by simoulin         ###   ########.fr       */
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

void		ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, len(s));
}
