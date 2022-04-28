/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:14:05 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 16:49:58 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_verif_relou_p(const char *s, int i)
{
	while (s[i] != '\0' && s[i] != 'd' && s[i] != 'i' &&
			s[i] != 'u' && s[i] != 'x' && s[i] != 'X' &&
			s[i] != 'c' && s[i] != 's' && s[i] != 'p')
	{
		if (s[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_p(const char *s, int i)
{
	if (s[i] == '\0' || s[i] == 'd' || s[i] == 'i'
			|| s[i] == 'u' || s[i] == 'x' || s[i] == 'X'
			|| s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == '%')
		return (1);
	return (0);
}

void		ft_number_p(const char c, va_list ap, int *nb, t_list_p *l)
{
	if (c == 'd' || c == 'i')
		ft_itoa_p(va_arg(ap, int), nb, l);
	if (c == 'u')
		ft_itoa_u_p(va_arg(ap, unsigned int), nb, l);
	if (c == 'x' || c == 'X')
		(c == 'x') ? ft_putnbr_h_p(va_arg(ap, int), nb, l, "0123456789abcdef") :
			ft_putnbr_h_p(va_arg(ap, int), nb, l, "0123456789ABCDEF");
}

void		ft_char_p(const char c, va_list ap, int *nb, t_list_p *l)
{
	char *str;

	if (c == 'c')
		ft_putchar_c_p(va_arg(ap, int), nb, l);
	if (c == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr_c_p(str, nb, l);
	}
}

int			ft_search_params_p(const char c, va_list ap, int *nb, t_list_p *l)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		ft_number_p(c, ap, nb, l);
	if (c == 'c' || c == 's')
		ft_char_p(c, ap, nb, l);
	if (c == 'p')
		ft_put_address_p((long)(va_arg(ap, void *)), nb, l, "0123456789abcdef");
	if (c == '%')
		ft_putchar_percent_p('%', nb, l);
	return (0);
}
