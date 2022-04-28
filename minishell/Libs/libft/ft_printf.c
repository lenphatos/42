/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:56:52 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 13:35:07 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_precision_p(const char *s, int i, t_list_p *l, va_list ap)
{
	l->is_precision = 1;
	i++;
	if (s[i] == '*')
	{
		l->precision = va_arg(ap, int);
		i++;
	}
	else if (s[i] >= '0' && s[i] <= '9')
		l->precision = ft_atoi_p(&s[i]);
	if (l->precision < 0)
	{
		l->precision = 0;
		l->is_precision = 0;
	}
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

int			ft_minus_p(const char *s, int i, t_list_p *l, va_list ap)
{
	if (s[i] == '-')
		i++;
	if (s[i] == '*' && s[i - 1] == '-')
	{
		l->minus = va_arg(ap, int);
		(l->minus > 0) ? (l->minus *= -1) : 0;
		i++;
	}
	if (s[i] == '*' && s[i - 1] != '-')
	{
		l->minus = va_arg(ap, int);
		i++;
	}
	else if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))
	{
		l->minus = ft_atoi_p(&s[i]);
		if (s[i - 1] == '-')
			l->minus *= -1;
	}
	while ((s[i] >= '0' && s[i] <= '9'))
		i++;
	return (i);
}

int			ft_zero_p(const char *s, int i, t_list_p *l, va_list ap)
{
	i++;
	if (s[i] == '*')
	{
		l->zero = va_arg(ap, int);
		i++;
	}
	else if (s[i] >= '0' && s[i] <= '9')
		l->zero = ft_atoi_p(&s[i]);
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
		i++;
	return (i);
}

int			ft_check_params_p(const char *s, int i, t_list_p *l, va_list ap)
{
	while (!(ft_check_p(s, i)))
	{
		(s[i] == '.') ? (i = ft_precision_p(s, i, l, ap)) : 0;
		(s[i] == '-' || (s[i] > '0' && s[i] <= '9')
		|| s[i] == '*') ? (i = ft_minus_p(s, i, l, ap)) : 0;
		(s[i] == '0') ? (i = ft_zero_p(s, i, l, ap)) : 0;
	}
	if ((l->is_precision && l->zero &&
				!(ft_verif_relou_p(s, i))) || (l->zero < 0))
	{
		l->minus = l->zero;
		l->zero = 0;
	}
	return (i);
}

int			ft_printf(const char *str, ...)
{
	int			i;
	int			nb;
	t_list_p	l;
	va_list		ap;

	nb = 0;
	i = -1;
	va_start(ap, str);
	while (str[++i])
	{
		if ((str[i] == '%' && str[i + 1]))
		{
			i++;
			l.is_precision = 0;
			l.precision = 0;
			l.zero = 0;
			l.minus = 0;
			i = ft_check_params_p(str, i, &l, ap);
			ft_search_params_p(str[i], ap, &nb, &l);
		}
		else
			ft_putchar_fd_p(str[i], &nb);
	}
	va_end(ap);
	return (nb);
}
