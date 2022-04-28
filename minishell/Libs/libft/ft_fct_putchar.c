/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:17:59 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 15:58:19 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen_p(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd_p(char c, int *nb)
{
	write(1, &c, 1);
	*nb += 1;
}

void	ft_putstr_fd_p(char *s, int *nb)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		ft_putchar_fd_p(s[i++], nb);
}
