/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:36:07 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/28 14:36:43 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_free(t_data *data)
{
	int i;

	i = 0;
	if (data->folder != 0)
	{
		while (data->folder[i])
		{
			free(data->folder[i]);
			data->folder[i++] = NULL;
		}
		free(data->folder);
		data->folder = NULL;
	}
	i = -1;
	if (data->tab != 0)
	{
		while (data->tab[++i])
		{
			free(data->tab[i]);
			data->tab[i] = NULL;
		}
		free(data->tab);
		data->tab = NULL;
	}
}

int			clickescape(t_data *data)
{
	system("killall afplay");
	ft_free(data);
	exit(0);
	return (0);
}

int			key_press(int keycode, t_data *data)
{
	data->key[keycode] = 1;
	if (keycode == 53)
	{
		system("killall afplay");
		ft_free(data);
		exit(0);
	}
	return (0);
}

int			key_release(int keycode, t_data *data)
{
	data->key[keycode] = 0;
	return (0);
}

int			ft_map_verif(char c)
{
	if (c != '0' && c != '1' && c != '2' &&
			c != 'N' && c != ' ' && c != 'S' &&
			c != 'E' && c != 'W')
		return (0);
	return (1);
}
