/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_print_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:16:22 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 16:41:58 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_print_zero(char *str, int *nb, t_list *l)
{
	int i;

	i = -1;
	(str[0] == '-') ? (ft_putchar_fd('-', nb)) : 0;
	if (l->is_precision == 0)
		while (++i < (l->zero - ft_strlen(str)))
			ft_putchar_fd('0', nb);
	else
		while (++i < (l->zero - ft_strlen(str)))
			ft_putchar_fd(' ', nb);
}

static void		ft_print_precision(char *str, int *nb, t_list *l)
{
	int	i;
	int	count;

	i = -1;
	count = (l->precision - ft_strlen(str));
	(str[0] == '-') ? (ft_putchar_fd('-', nb)) : 0;
	(str[0] == '-') ? (count = l->precision - (ft_strlen(str) - 1)) : 0;
	if (ft_strlen(str) == 1 && str[0] == '0' && l->is_precision)
		count = l->precision;
	while (++i < count)
		ft_putchar_fd('0', nb);
}

void			ft_print_spaces(const char *str, int *nb, t_list *l)
{
	int i;
	int count;

	i = -1;
	count = ft_strlen(str);
	(l->precision > ft_strlen(str)) ? (count = l->precision) : 0;
	if (ft_strlen(str) == 1 && str[0] == '0' && l->is_precision)
		count = l->precision;
	while (++i < (l->minus - count))
		ft_putchar_fd(' ', nb);
}

void			ft_print_spaces_back(const char *str, int *nb, t_list *l)
{
	int i;
	int count;

	i = -1;
	count = ft_strlen(str);
	(l->precision > ft_strlen(str)) ? (count = l->precision) : 0;
	if (ft_strlen(str) == 1 && str[0] == '0' && l->is_precision)
		count = 0;
	l->minus *= -1;
	while (++i < (l->minus - count))
		ft_putchar_fd(' ', nb);
}

void			ft_choose(char *str, int *nb, t_list *l)
{
	int i;

	i = 0;
	((str[0] == '-' && l->precision) || (str[0] == '-' && l->zero)
	|| (str[0] == '0' && l->is_precision)) ? (i = 1) : 0;
	if (l->minus > 0)
		ft_print_spaces(str, nb, l);
	if (l->zero > 0)
		ft_print_zero(str, nb, l);
	if (l->precision > 0)
		ft_print_precision(str, nb, l);
	if (!(str[0] == '0' && str[1] == '\0' && l->is_precision))
		ft_putstr_fd(&str[i], nb);
	if (l->minus < 0)
		ft_print_spaces_back(str, nb, l);
}
