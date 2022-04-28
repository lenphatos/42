/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:28:56 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/10 15:28:57 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_sprite_h(t_data *data)
{
	if (data->angle >= 0 && data->angle < PI / 2)
		data->lll = (64 - (data->x - (int)data->x / 64 * 64)) /
		(tan(-data->angle + PI / 2) + 1) / 64 * data->ww[0];
	else if (data->angle >= PI && data->angle < 3 * PI / 2)
		data->lll = (data->x - (int)data->x / 64 * 64) /
		(tan(-data->angle + PI / 2) + 1) / 64 * data->ww[0];
	else if (data->angle >= 3 * PI / 2 && data->angle < 2 * PI)
		data->lll = data->ww[0] - (64 - (data->x - (int)data->x / 64 * 64)) /
		(tan(data->angle + PI / 2) + 1) / 64 * data->ww[0];
	else if (data->angle >= PI / 2 && data->angle < PI)
		data->lll = data->ww[0] - (data->x - (int)data->x / 64 * 64) /
		(tan(data->angle + PI / 2) + 1) / 64 * data->ww[0];
}

void			ft_sprite_v(t_data *data)
{
	if (data->angle >= PI / 2 && data->angle < PI)
		data->hhh = (data->y - (int)data->y / 64 * 64) /
		(tan(-data->angle) + 1) / 64 * data->ww[0];
	else if (data->angle >= 3 * PI / 2 && data->angle < 2 * PI)
		data->hhh = (64 - (data->y - (int)data->y / 64 * 64)) /
		(tan(-data->angle) + 1) / 64 * data->ww[0];
	else if (data->angle >= 0 && data->angle < PI / 2)
		data->hhh = data->ww[0] - (data->y - (int)data->y / 64 * 64) /
		(tan(data->angle) + 1) / 64 * data->ww[0];
	else if (data->angle >= PI && data->angle < 3 * PI / 2)
		data->hhh = data->ww[0] - (64 - (data->y - (int)data->y / 64 * 64)) /
		(tan(data->angle) + 1) / 64 * data->ww[0];
}

void			ft_where_iam_h(t_data *data)
{
	if (data->angle >= 0 && data->angle <= PI)
		data->l = (data->x - (int)data->x / 64 * 64) / 64 * data->ww[1];
	else
		data->l = (data->x - (int)data->x / 64 * 64) / 64 * data->ww[2];
}

void			ft_where_iam_v(t_data *data)
{
	if ((data->angle >= 0 && data->angle <= (PI / 2))
	|| (data->angle >= PI + PI / 2 && data->angle <= PI * 2))
		data->h = (data->y - (int)data->y / 64 * 64) / 64 * data->ww[3];
	else
		data->h = (data->y - (int)data->y / 64 * 64) / 64 * data->ww[4];
}
