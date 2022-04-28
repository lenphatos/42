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

static void		ft_print_zero_p(char *str, int *nb, t_list_p *l)
{
	int i;

	i = -1;
	(str[0] == '-') ? (ft_putchar_fd_p('-', nb)) : 0;
	if (l->is_precision == 0)
		while (++i < (l->zero - ft_strlen_p(str)))
			ft_putchar_fd_p('0', nb);
	else
		while (++i < (l->zero - ft_strlen_p(str)))
			ft_putchar_fd_p(' ', nb);
}

static void		ft_print_precision_p(char *str, int *nb, t_list_p *l)
{
	int	i;
	int	count;

	i = -1;
	count = (l->precision - ft_strlen_p(str));
	(str[0] == '-') ? (ft_putchar_fd_p('-', nb)) : 0;
	(str[0] == '-') ? (count = l->precision - (ft_strlen_p(str) - 1)) : 0;
	if (ft_strlen_p(str) == 1 && str[0] == '0' && l->is_precision)
		count = l->precision;
	while (++i < count)
		ft_putchar_fd_p('0', nb);
}

void			ft_print_spaces_p(const char *str, int *nb, t_list_p *l)
{
	int i;
	int count;

	i = -1;
	count = ft_strlen_p(str);
	(l->precision > ft_strlen_p(str)) ? (count = l->precision) : 0;
	if (ft_strlen_p(str) == 1 && str[0] == '0' && l->is_precision)
		count = l->precision;
	while (++i < (l->minus - count))
		ft_putchar_fd_p(' ', nb);
}

void			ft_print_spaces_back_p(const char *str, int *nb, t_list_p *l)
{
	int i;
	int count;

	i = -1;
	count = ft_strlen_p(str);
	(l->precision > ft_strlen_p(str)) ? (count = l->precision) : 0;
	if (ft_strlen_p(str) == 1 && str[0] == '0' && l->is_precision)
		count = 0;
	l->minus *= -1;
	while (++i < (l->minus - count))
		ft_putchar_fd_p(' ', nb);
}

void			ft_choose_p(char *str, int *nb, t_list_p *l)
{
	int i;

	i = 0;
	((str[0] == '-' && l->precision) || (str[0] == '-' && l->zero)
	|| (str[0] == '0' && l->is_precision)) ? (i = 1) : 0;
	if (l->minus > 0)
		ft_print_spaces_p(str, nb, l);
	if (l->zero > 0)
		ft_print_zero_p(str, nb, l);
	if (l->precision > 0)
		ft_print_precision_p(str, nb, l);
	if (!(str[0] == '0' && str[1] == '\0' && l->is_precision))
		ft_putstr_fd_p(&str[i], nb);
	if (l->minus < 0)
		ft_print_spaces_back_p(str, nb, l);
}
