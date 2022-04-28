/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:14:09 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/12 17:55:29 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long		ft_pimp(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = -1;
	while (str[i++] >= '0' && str[i - 1] <= '9')
	{
		(result == -1) ? result++ : 0;
		result = result * 10 + str[i - 1] - 48;
	}
	return (result);
}

int			ft_atoi_pimp(char *str, long *result)
{
	int i;

	i = 0;
	result[0] = ft_pimp(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	result[1] = ft_pimp(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	result[2] = ft_pimp(&str[i]);
	result[3] = -1;
	if (result[0] < 0 || result[0] > 255
		|| result[1] < 0 || result[1] > 255
		|| result[2] < 0 || result[2] > 255)
		return (0);
	while (str[i])
		if (str[i] == ',' || str[i++] == ' ')
			return (0);
	return (1);
}

int			ft_verif_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' &&
		str[i] != '2' && str[i] != '3' &&
		str[i] != '4' && str[i] != '5' &&
		str[i] != '6' && str[i] != '7' &&
		str[i] != '8' && str[i] != '9' &&
		str[i] != ',' && str[i] != ' ')
			return (0);
		else
			i++;
	}
	return (1);
}

int			ft_calculate_color(char *str, int *result)
{
	int		i;
	long	one[4];

	i = 1;
	if (str[i] != ' ')
		return (0);
	while (str[i] == ' ')
		i++;
	if (!ft_verif_color(&str[i]))
		return (0);
	if (!ft_atoi_pimp(&str[i], one))
		return (0);
	*result = ((one[0] & 0xff) << 16) +
	((one[1] & 0xff) << 8) + (one[2] & 0xff);
	return (1);
}

int			ft_texte_floor_sky(t_data *data, int i)
{
	if (data->path[i][0] == 'C' && data->sky == -1)
	{
		if (!(ft_calculate_color(data->path[i], &data->sky)))
			return (0);
	}
	else if (data->path[i][0] == 'F' && data->floor == -1)
	{
		if (!(ft_calculate_color(data->path[i], &data->floor)))
			return (0);
	}
	else
		return (0);
	return (1);
}
