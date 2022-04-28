/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:53:06 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/12 17:56:08 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_number_element(t_data *data)
{
	int i;
	int verif;

	i = -1;
	verif = 0;
	data->count_txt = 0;
	while (data->folder[++i])
	{
		if (data->folder[i][0] == 'R')
		{
			verif++;
			data->count_txt++;
		}
		else if ((data->folder[i][0] == 'R')
		|| (data->folder[i][0] == 'N') || (data->folder[i][0] == 'S')
		|| (data->folder[i][0] == 'E') || (data->folder[i][0] == 'W')
		|| (data->folder[i][0] == 'C') || (data->folder[i][0] == 'F'))
			data->count_txt++;
	}
	(verif > 1) ? (data->count_txt = 7) : 0;
	(data->count_txt != 8) ? (data->cheror[0] = 1) : 0;
	return ((data->count_txt != 8) ? 0 : 1);
}

static int		ft_texte_north_south(t_data *data, int i)
{
	if (data->path[i][0] == 'N' &&
	data->path[i][1] == 'O' && data->img_north == NULL)
	{
		if (!(data->img_north = mlx_xpm_file_to_image(data->mlx_ptr,
			ft_path_north(data->path[i]), &data->ww[1], &data->hh[1])))
			return (0);
	}
	else if (data->path[i][0] == 'S' &&
	data->path[i][1] == 'O' && data->img_south == NULL)
	{
		if (!(data->img_south = mlx_xpm_file_to_image(data->mlx_ptr,
			ft_path_south(data->path[i]), &data->ww[2], &data->hh[2])))
			return (0);
	}
	else
		return (0);
	return (1);
}

static int		ft_texte_east_weast(t_data *data, int i)
{
	if (data->path[i][0] == 'E' &&
	data->path[i][1] == 'A' && data->img_east == NULL)
	{
		if (!(data->img_east = mlx_xpm_file_to_image(data->mlx_ptr,
			ft_path_east(data->path[i]), &data->ww[3], &data->hh[3])))
			return (0);
	}
	else if (data->path[i][0] == 'W' &&
	data->path[i][1] == 'E' && data->img_weast == NULL)
	{
		if (!(data->img_weast = mlx_xpm_file_to_image(data->mlx_ptr,
			ft_path_weast(data->path[i]), &data->ww[4], &data->hh[4])))
			return (0);
	}
	else
		return (0);
	return (1);
}

static int		ft_texte_sprite(t_data *data, int i)
{
	if (data->path[i][0] == 'S' &&
	data->path[i][1] == ' ' && data->img_sprite == NULL)
	{
		if (!(data->img_sprite = mlx_xpm_file_to_image(data->mlx_ptr,
			ft_path_sprite(data->path[i]), &data->ww[0], &data->hh[0])))
			return (0);
	}
	else
		return (0);
	return (1);
}

int				ft_take_texture(t_data *data)
{
	int i;

	i = -1;
	while (data->path[++i])
	{
		if (data->path[i][0] == 'S' && data->path[i][1] == ' ')
		{
			if (!ft_texte_sprite(data, i))
				return (0);
		}
		else if ((data->path[i][0] == 'N') || (data->path[i][0] == 'S'))
			if (!ft_texte_north_south(data, i))
				return (0);
		if ((data->path[i][0] == 'E') || (data->path[i][0] == 'W'))
			if (!ft_texte_east_weast(data, i))
				return (0);
		if (data->path[i][0] == 'C' || data->path[i][0] == 'F')
			if (!ft_texte_floor_sky(data, i))
				return (0);
	}
	return (1);
}
