/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:07:51 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/24 13:07:53 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_regul(t_data *data, char **av, int ac)
{
	if (ac > 2 && ft_strcmp("--save", av[2]) == 0)
		while (data->width % 4 != 0)
			data->width++;
	return (1);
}

int			ft_print_img(t_data *data)
{
	if (data->i == 0)
	{
		data->i = 1;
		save_bmp(data);
		return (0);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->mlx_img, 0, 0);
	return (1);
}

int			ft_check_cub(char *str)
{
	int i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strcmp(&str[i], ".cub") != 0)
		return (0);
	return (1);
}

int			check_bmp(int ac, char **av, t_data *data)
{
	if (ac == 3 && (ft_strcmp("--save", av[2]) == 0))
	{
		data->i = 0;
		ft_cub3d(data);
		return (0);
	}
	else if (ac > 3 || (ac == 3 && (ft_strcmp("--save", av[2]) != 0)))
	{
		ft_putstr("Error\n->Wrong arguments<-\n");
		return (0);
	}
	return (1);
}

int			ft_verif_char_map(t_data *data)
{
	int i;
	int a;
	int nb;

	i = -1;
	nb = 0;
	while (data->tab[++i])
	{
		a = -1;
		while (data->tab[i][++a])
		{
			if (data->tab[i][a] != '0' || data->tab[i][a] != '2'
			|| data->tab[i][a] != 'E' || data->tab[i][a] != 'W'
			|| data->tab[i][a] != 'N' || data->tab[i][a] != 'S')
				nb++;
			if (data->tab[i][a] != '1' && data->tab[i][a] != '0' &&
					data->tab[i][a] != '2' && data->tab[i][a] != '#' &&
					data->tab[i][a] != 'N' && data->tab[i][a] != 'S' &&
					data->tab[i][a] != 'E' && data->tab[i][a] != 'W')
				return (0);
		}
	}
	if (nb < 1)
		return (0);
	return (1);
}
