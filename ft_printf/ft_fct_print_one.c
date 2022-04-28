/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:55:32 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 15:49:38 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putchar_c(char c, int *nb, t_list *l)
{
	int i;

	i = 0;
	while (i++ < (l->minus - 1))
		ft_putchar_fd(' ', nb);
	ft_putchar_fd(c, nb);
	(l->minus < 0) ? (l->minus *= -1) : 0;
	while (i++ < (l->minus))
		ft_putchar_fd(' ', nb);
}

void		ft_putchar_percent(char c, int *nb, t_list *l)
{
	int i;

	i = 0;
	if (l->zero)
	{
		while (i < (l->zero - 1))
		{
			ft_putchar_fd('0', nb);
			i++;
		}
		ft_putchar_fd(c, nb);
	}
	else
	{
		while (i++ < (l->minus - 1))
			ft_putchar_fd(' ', nb);
		ft_putchar_fd(c, nb);
		(l->minus < 0) ? (l->minus *= -1) : 0;
		while (i++ < (l->minus))
			ft_putchar_fd(' ', nb);
	}
}

void		ft_putstr_back_c(char *str, int *nb, t_list *l)
{
	int		i;
	int		count;

	i = -1;
	(l->minus < 0) ? (l->minus *= -1) : 0;
	count = ft_strlen(str);
	(l->precision < ft_strlen(str) && l->is_precision) ?
		(count = l->precision) : 0;
	while (++i < (l->minus - count))
		ft_putchar_fd(' ', nb);
}

void		ft_putstr_c(char *str, int *nb, t_list *l)
{
	int		i;
	int		a;
	int		count;

	i = 0;
	a = 0;
	(str == NULL) ? (str = "(null)") : 0;
	count = ft_strlen(str);
	(l->precision < ft_strlen(str) && l->is_precision) ?
		(count = l->precision) : 0;
	while (i < (l->minus - count))
	{
		ft_putchar_fd(' ', nb);
		i++;
	}
	if (l->is_precision)
		while (a < l->precision && str[a])
			ft_putchar_fd(str[a++], nb);
	else
		while (str[a])
			ft_putchar_fd(str[a++], nb);
	if (l->minus < 0)
		ft_putstr_back_c(str, nb, l);
}
