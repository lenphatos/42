/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:52:59 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/16 11:10:04 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_viseur(t_data *data, float x, float y)
{
	if ((x >= data->width / 2 - 10 && x <= data->width / 2 + 10) &&
	(y > (data->height / 2 - 2) && y < (data->height / 2 + 1)))
		data->addr[(int)(x + y * (int)data->width)] = 111111;
	if ((x > data->width / 2 - 1 && x < data->width / 2 + 2) &&
	(y > (data->height / 2 - 10) && y < (data->height / 2 + 9)))
		data->addr[(int)(x + y * (int)data->width)] = 111111;
}

void			ft_print_wall(t_data *data, float x, float y)
{
	if ((data->angle >= 0 && data->angle <= PI) && data->color == 1)
		data->addr[(int)(x + y * (int)data->width)] =
		data->texture[1][data->test[1] * data->ww[1] + (int)data->l];
	else if ((data->angle > PI && data->angle < PI * 2) && data->color == 1)
		data->addr[(int)(x + y * (int)data->width)] =
		data->texture[2][data->test[2] * data->ww[2] + (int)data->l];
	else if (((data->angle >= 0 && data->angle <= (PI / 2))
			|| (data->angle >= PI + PI / 2
			&& data->angle <= PI * 2)) && data->color == 0)
		data->addr[(int)(x + y * (int)data->width)] =
		data->texture[3][data->test[3] * data->ww[3] + (int)data->h];
	else
		data->addr[(int)(x + y * (int)data->width)] =
		data->texture[4][data->test[4] * data->ww[4] + (int)data->h];
}

void			ft_print_sprite(t_data *data, float x, float y)
{
	if (data->color1 == 1)
		data->addr[(int)(x + y * (int)data->width)] =
		data->texture[0][data->test[0] * data->ww[0] + (int)data->lll];
	else
		data->addr[(int)(x + y * (int)data->width)] =
		data->texture[0][data->test[0] * data->ww[0] + (int)data->hhh];
}

void			ft_print_wall_sprite(t_data *data, float x, float y)
{
	if (y < ((data->height + data->dev) / 2 - data->hm / 2))
		data->addr[(int)(x + y * data->width)] = data->sky;
	if (y >= ((data->height + data->dev) / 2 - data->hm / 2) &&
			y <= ((data->height + data->dev) / 2 + data->hm / 2))
		ft_print_wall(data, x, y);
	if (y > ((data->height + data->dev) / 2 + data->hm / 2))
		data->addr[(int)(x + y * data->width)] = data->floor;
	if (data->dist_sprite < data->distplayer && (y > ((data->height + data->dev)
	/ 2 - data->hs / 2) && y < ((data->height + data->dev) / 2 + data->hs / 2)))
		ft_print_sprite(data, x, y);
	ft_viseur(data, x, y);
}
