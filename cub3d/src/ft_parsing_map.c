/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:48:05 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 11:35:18 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_end_lines(t_data *data)
{
	int y;
	int x;
	int diff;
	int size[data->count];

	x = 0;
	y = -1;
	while (data->tab[++y])
		size[y] = ft_strlen(data->tab[y]);
	y = -1;
	while (data->tab[++y])
	{
		if (data->tab[y][ft_strlen(data->tab[y]) - 1] != '1')
			return (0);
		if (y < data->count && size[y] > size[y + 1])
		{
			diff = size[y] - size[y + 1];
			while (data->tab[y][++diff])
				if (data->tab[y][diff] != '1' || data->tab[y][diff] != ' ')
					return (0);
		}
	}
	return (1);
}

int			check_fila_lines(t_data *data, int fila)
{
	int i;

	i = -1;
	while (data->tab[fila][++i])
	{
		if (data->tab[fila][i] != '1' &&
			data->tab[fila][i] != '#' &&
			data->tab[fila][i] != ' ')
			return (0);
	}
	return (1);
}

int			check_zero(t_data *data)
{
	int y;
	int x;

	x = -1;
	y = 0;
	while (data->tab[++y])
	{
		x = -1;
		while (data->tab[y][++x])
			if (data->tab[y][x] == '0' || data->tab[y][x] == 'W'
			|| data->tab[y][x] == 'E' || data->tab[y][x] == 'S'
			|| data->tab[y][x] == 'N' || data->tab[y][x] == '2')
				if (data->tab[y - 1][x] == ' ' || data->tab[y - 1][x] == '#'
				|| data->tab[y + 1][x] == ' ' || data->tab[y + 1][x] == '#'
				|| data->tab[y][x - 1] == ' ' || data->tab[y][x - 1] == '#'
				|| data->tab[y][x + 1] == ' ' || data->tab[y][x + 1] == '#')
					return (0);
	}
	return (1);
}

int			ft_check_map(t_data *data)
{
	int nb;

	nb = 0;
	while (data->tab[nb])
		nb++;
	if (!check_fila_lines(data, 0)
	|| !ft_verif_char_map(data)
	|| !check_fila_lines(data, nb - 1)
	|| !check_zero(data))
	{
		ft_putstr("Error\n->wrong map<-\n");
		return (0);
	}
	return (1);
}

int			ft_locate(t_data *data)
{
	int i;
	int mb;

	i = -1;
	mb = 0;
	while (data->map[mb])
		mb++;
	if (!(data->tab = malloc(sizeof(char *) * mb + 1)))
		return (0);
	while (data->map[++i])
		data->tab[i] = ft_nospace_m(data->map[i],
				ft_size_array(data->map));
	data->tab[i] = 0;
	return (1);
}
