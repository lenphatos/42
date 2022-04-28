/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:00:41 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/11 14:39:58 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_init_horizontal(t_data *data)
{
	if (data->angle >= 0 && data->angle <= PI)
	{
		data->y = floor(data->posy / 64) * 64 - 0.0001;
		data->xa = (64 / tan(data->angle));
		data->ya = -64;
	}
	else
	{
		data->y = floor(data->posy / 64) * 64 + 64;
		data->xa = (64 / tan(data->angle) * -1);
		data->ya = 64;
	}
	data->x = data->posx + (data->posy - data->y) / tan(data->angle);
}

static void		ft_init_vertical(t_data *data)
{
	if ((data->angle >= 0 && data->angle <= (PI / 2))
			|| (data->angle >= PI + PI / 2 && data->angle <= PI * 2))
	{
		data->x = floor(data->posx / 64) * 64 + 64;
		data->ya = (64 * tan(data->angle) * -1);
		data->xa = 64;
	}
	else
	{
		data->x = floor(data->posx / 64) * 64 - 0.0001;
		data->ya = (64 * tan(data->angle));
		data->xa = -64;
	}
	data->y = data->posy + ((data->posx - data->x) * tan(data->angle));
}

float			ft_horizontal(t_data *data)
{
	ft_init_horizontal(data);
	while ((data->y / 64) < data->count && (data->y / 64) >= 0 &&
			(data->x / 64) < data->maxx && (data->x / 64) >= 0)
	{
		if (data->tab[(int)data->y / 64][(int)data->x / 64]
				== '2' && data->lll == -1)
		{
			ft_sprite_h(data);
			data->dist_sprite_h = sqrt(pow(floor(data->x / 64) * 64 + 32 -
			data->posx, 2) + pow(floor(data->y / 64) * 64 + 32 -
			data->posy, 2));
		}
		if (data->tab[(int)data->y / 64][(int)data->x / 64] == '1')
		{
			ft_where_iam_h(data);
			return (sqrt(pow(data->posx - data->x, 2) +
						pow(data->posy - data->y, 2)));
		}
		data->y += data->ya;
		data->x += data->xa;
	}
	return (100000);
}

float			ft_vertical(t_data *data)
{
	ft_init_vertical(data);
	while ((data->y / 64) < data->count && (data->y / 64) >= 0 &&
			(data->x / 64) < data->maxx && (data->x / 64) >= 0)
	{
		if (data->tab[(int)data->y / 64][(int)data->x / 64]
				== '2' && data->hhh == -1)
		{
			ft_sprite_v(data);
			data->dist_sprite_v = sqrt(pow(floor(data->x / 64) * 64 + 32 -
			data->posx, 2) + pow(floor(data->y / 64) * 64 + 32 -
			data->posy, 2));
		}
		if (data->tab[(int)data->y / 64][(int)data->x / 64] == '1')
		{
			ft_where_iam_v(data);
			return (sqrt(pow(data->posx - data->x, 2) +
						pow(data->posy - data->y, 2)));
		}
		data->y += data->ya;
		data->x += data->xa;
	}
	return (100000);
}
