/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:44:04 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 16:41:28 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putnbr_h(unsigned int n, int *nbr, t_list *l, char *base)
{
	unsigned int		i;
	unsigned int		nb;
	unsigned int		count;
	char				*str;

	i = 0;
	nb = n;
	count = 0;
	nb = n;
	(n < 0) ? (nb = (4294967295 - n)) : 0;
	while ((nb = (nb / 16)))
		count++;
	if (!(str = malloc(sizeof(char) * count + 2)))
		return ;
	nb = n;
	while (nb >= 16 && ((str[i++] = base[nb % 16]) || 1))
		nb = nb / 16;
	str[i++] = base[nb % 16];
	str[count + 1] = '\0';
	ft_swp(str, nbr, l);
	free(str);
}

static char		*ft_join(char *str, int i)
{
	int		a;
	char	*s1;

	a = 0;
	s1 = "x0";
	while (a < 2)
		str[i++] = s1[a++];
	str[i] = '\0';
	return (str);
}

void			ft_put_address(long n, int *nbr, t_list *l, char *base)
{
	int		i;
	int		count;
	int		count1;
	long	nb;
	char	*str;

	i = 0;
	nb = n;
	count1 = 2;
	count = 0;
	(n == 0) ? (count1 = 3) : 0;
	while ((nb = (nb / 16)))
		count++;
	if (!(str = malloc(sizeof(char) * (count + 1 + count1))))
		return ;
	nb = n;
	while (nb >= 16 && ((str[i++] = base[nb % 16]) || 1))
		nb = nb / 16;
	str[i++] = base[nb % 16];
	str[i] = '\0';
	str = ft_join(str, i);
	ft_swp(str, nbr, l);
	free(str);
}
