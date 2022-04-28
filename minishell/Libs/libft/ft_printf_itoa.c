/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:37:58 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 15:53:09 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_swp_p(char *str, int *nbr, t_list_p *l)
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
	ft_choose_p(str, nbr, l);
}

void	ft_itoa_p(long n, int *nbr, t_list_p *l)
{
	long	i;
	long	count;
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
		return ;
	nb = n;
	if (nb < 0 && (nb = -nb))
		str[count] = '-';
	while (nb > 9 && ((str[i++] = (nb % 10) + 48) || 1))
		nb = nb / 10;
	str[i++] = nb + 48;
	str[count + 1] = '\0';
	ft_swp_p(str, nbr, l);
	free(str);
}

void	ft_itoa_u_p(unsigned int n, int *nbr, t_list_p *l)
{
	char				*str;
	unsigned int		i;
	unsigned int		nb;
	unsigned int		count;

	i = 0;
	nb = n;
	count = 0;
	while ((nb = (nb / 10)))
		count++;
	if (!(str = malloc(sizeof(char) * count + 2)))
		return ;
	nb = n;
	while (nb > 9 && ((str[i++] = (nb % 10) + 48) || 1))
		nb = nb / 10;
	str[i++] = nb + 48;
	str[i++] = '\0';
	ft_swp_p(str, nbr, l);
	free(str);
}

long	ft_atoi_p(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i++] >= '0' && str[i - 1] <= '9')
		result = result * 10 + str[i - 1] - 48;
	return (result * sign);
}
