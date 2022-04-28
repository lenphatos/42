/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:44:53 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/09 13:39:13 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_swp(char *str)
{
	int		i;
	int		j;
	int		p;
	char	c;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	p = j;
	j -= 1;
	while (i <= (p / 2) - 1)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		count;
	long	nb;
	char	*str;

	i = 0;
	nb = (long)n;
	count = 0;
	if (n < 0)
		count = 1;
	while ((nb = (nb / 10)))
		count++;
	if (!(str = malloc(sizeof(char) * count + 2)))
		return (0);
	nb = (long)n;
	if (nb < 0 && (nb = -nb))
		str[count] = '-';
	while (nb > 9 && ((str[i++] = (nb % 10) + 48) || 1))
		nb = nb / 10;
	str[i++] = nb + 48;
	str[count + 1] = '\0';
	ft_swp(str);
	return (str);
}
