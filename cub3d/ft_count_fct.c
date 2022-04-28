/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:54:24 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 11:32:37 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_size_array(char **tab)
{
	int i;
	int nb;

	i = 0;
	nb = ft_strlen(tab[i]);
	while (tab[++i])
		if (nb < ft_strlen(tab[i]))
			nb = ft_strlen(tab[i]);
	return (nb);
}

int		ft_size(t_data *data)
{
	int i;

	i = 0;
	data->count = 0;
	data->maxx = 0;
	while (data->tab[data->count])
		data->count++;
	data->maxx = ft_strlen(data->tab[i]);
	i = -1;
	while (data->tab[++i])
		if (data->maxx < ft_strlen(data->tab[i]))
			data->maxx = ft_strlen(data->tab[i]);
	return (1);
}

int		ft_count_one(t_data *data)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (data->map[++i])
		count++;
	count += 1;
	return (count);
}

int		ft_count_t(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i++])
		if (str[i] == '0' || str[i] == '1'
				|| str[i] == '2' || str[i] == 'N'
				|| str[i] == 'S' || str[i] == 'E'
				|| str[i] == 'W')
			count++;
	return (count);
}

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

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
