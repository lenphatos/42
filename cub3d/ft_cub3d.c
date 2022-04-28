/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:22:33 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/24 15:11:14 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	ft_distance(t_data *data)
{
	float	value_one;
	float	value_two;

	value_one = ft_horizontal(data);
	value_two = ft_vertical(data);
	if (value_one < value_two)
		data->color = 1;
	else
		data->color = 0;
	return ((value_one < value_two) ? (value_one) : (value_two));
}

void			ft_cub3d_bis(t_data *data, float x)
{
	data->angle = ((x / data->width) * 60 + data->deviation) * PI / 180;
	while (data->angle > 2 * PI)
		data->angle -= 2 * PI;
	while (data->angle < 0)
		data->angle += 2 * PI;
	data->distplayer = ft_distance(data);
	data->hm = 64 / data->distplayer * data->width;
	if (data->dist_sprite_h <= data->dist_sprite_v &&
		data->dist_sprite_h != 10000000000)
	{
		data->dist_sprite = data->dist_sprite_h;
		data->color1 = 1;
	}
	else if (data->dist_sprite_v < data->dist_sprite_h &&
		data->dist_sprite_h != 10000000000)
	{
		data->dist_sprite = data->dist_sprite_v;
		data->color1 = 0;
	}
	data->hs = (64 / (data->dist_sprite) * data->width) / 1.3;
}

void			ft_init_s(t_data *data)
{
	data->dist_sprite = 1000000000;
	data->dist_sprite_v = 1000000000;
	data->dist_sprite_h = 1000000000;
	data->lll = -1;
	data->hhh = -1;
}

void			ft_init_texture_h(t_data *data, float y)
{
	data->test[0] = (int)(y - ((data->height + data->dev) /
	2 - data->hs / 2)) / data->hs * data->hh[0];
	data->test[1] = (int)(y - ((data->height + data->dev) /
	2 - data->hm / 2)) / data->hm * data->hh[1];
	data->test[2] = (int)(y - ((data->height + data->dev) /
	2 - data->hm / 2)) / data->hm * data->hh[2];
	data->test[3] = (int)(y - ((data->height + data->dev) /
	2 - data->hm / 2)) / data->hm * data->hh[3];
	data->test[4] = (int)(y - ((data->height + data->dev) /
	2 - data->hm / 2)) / data->hm * data->hh[4];
}

void			ft_cub3d(t_data *data)
{
	float	x;

	x = 0;
	data->xx = data->width;
	while (--data->xx)
	{
		data->yy = data->height;
		ft_init_s(data);
		ft_cub3d_bis(data, x);
		while (--data->yy)
		{
			ft_init_texture_h(data, data->yy);
			ft_print_wall_sprite(data, data->xx, data->yy);
		}
		x++;
	}
	if (!ft_print_img(data))
		return ;
}
