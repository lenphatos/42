/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:49:57 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/28 14:36:33 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_moove_front_back(t_data *data)
{
	if (data->key[13])
	{
		data->t_posy += cos((data->deviation + 120) * RAD) * data->speed;
		data->t_posx += sin((data->deviation + 120) * RAD) * data->speed;
	}
	if (data->key[1])
	{
		data->t_posy -= cos((data->deviation + 120) * RAD) * data->speed;
		data->t_posx -= sin((data->deviation + 120) * RAD) * data->speed;
	}
}

static void		ft_moove_right_left(t_data *data)
{
	if (data->key[2])
	{
		data->t_posy += sin((data->deviation + 120) * RAD) * data->speed;
		data->t_posx -= cos((data->deviation + 120) * RAD) * data->speed;
	}
	if (data->key[0])
	{
		data->t_posy -= sin((data->deviation + 120) * RAD) * data->speed;
		data->t_posx += cos((data->deviation + 120) * RAD) * data->speed;
	}
}

void			ft_verif(t_data *data)
{
	if (data->t_posy >= 0 && (data->t_posy / 64) <= data->count &&
	(data->tab[(int)data->t_posy / 64][(int)data->posx / 64] != '1'
	&& data->tab[(int)data->t_posy / 64][(int)data->posx / 64] != '2'))
		data->posy = data->t_posy;
	if (data->t_posx >= 0 && (data->t_posx / 64) <= data->maxx &&
	(data->tab[(int)data->posy / 64][(int)data->t_posx / 64] != '1') &&
	(data->tab[(int)data->posy / 64][(int)data->t_posx / 64] != '2'))
		data->posx = data->t_posx;
}

int				ft_decaler(t_data *data)
{
	data->t_posx = data->posx;
	data->t_posy = data->posy;
	if (data->key[257])
		data->speed = 11;
	else
		data->speed = 8;
	if (data->key[126] && data->dev < (data->height / 4))
		data->dev += 11;
	if (data->key[125] && data->dev > -(data->height / 4))
		data->dev += -11;
	if (data->key[13] || data->key[1])
		ft_moove_front_back(data);
	if (data->key[2] || data->key[0])
		ft_moove_right_left(data);
	ft_verif(data);
	if (data->key[8])
		data->dev = -87;
	if (data->key[124] || data->key[123])
		data->deviation += (data->key[124] ? -ANGLE * 5 : ANGLE * 5);
	return (1);
}
