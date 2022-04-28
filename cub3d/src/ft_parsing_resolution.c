/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_resolution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:09:18 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/11 14:45:33 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_check_reso(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' &&
		str[i] != '2' && str[i] != '3' && str[i] != '4' &&
		str[i] != '5' && str[i] != '6' && str[i] != '7' &&
		str[i] != '8' && str[i] != '9' && str[i] != ' ')
			return (0);
		else
			i++;
	}
	return (1);
}

int				ft_resolution(t_data *data)
{
	int i;
	int j;

	i = -1;
	j = 1;
	while (data->path[++i])
		if (data->path[i][0] == 'R' && data->check_reso == 0)
		{
			data->check_reso = 1;
			if (!ft_check_reso(&data->path[i][1]) || data->path[i][1] != ' ')
				return (0);
			while (data->path[i][j] == ' ')
				j++;
			data->width = ft_atoi(&data->path[i][j]);
			while (data->path[i][j] >= '0' && data->path[i][j] <= '9')
				j++;
			while (data->path[i][j] == ' ')
				j++;
			data->height = ft_atoi(&data->path[i][j]);
			while (data->path[i][j] >= '0' && data->path[i][j] <= '9')
				j++;
			if (data->path[i][j] != '\0')
				return (0);
		}
	return (1);
}
