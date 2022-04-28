/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:14:18 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/01 15:45:55 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main_loop(t_data *data)
{
	ft_cub3d(data);
	ft_decaler(data);
	return (0);
}

int			ft_init(t_data *data)
{
	data->i = -1;
	while (++data->i < 280)
		data->key[data->i] = 0;
	data->deviation = 0;
	data->color = 0;
	data->posx = 0;
	data->posy = 0;
	data->dev = 0;
	data->error = 0;
	data->check_reso = 0;
	data->map = 0;
	data->sky = -1;
	data->floor = -1;
	data->tab = 0;
	data->folder = 0;
	data->cheror[0] = -1;
	data->index = 0;
	system("afplay ./music/techno.mp3 & ");
	return (1);
}

int			ft_init_texture(t_data *data)
{
	data->mlx_img = mlx_new_image(data->mlx_ptr,
			data->width, data->height);
	data->addr = (int *)mlx_get_data_addr(data->mlx_img,
			&data->bpp, &data->sl, &data->endian);
	if (!ft_take_texture(data))
	{
		ft_putstr("Error\n->texture<-\n");
		return (0);
	}
	data->texture[0] = (int *)mlx_get_data_addr(data->img_sprite,
			&data->bpp, &data->sl, &data->endian);
	data->texture[1] = (int *)mlx_get_data_addr(data->img_north,
			&data->bpp, &data->sl, &data->endian);
	data->texture[2] = (int *)mlx_get_data_addr(data->img_south,
			&data->bpp, &data->sl, &data->endian);
	data->texture[3] = (int *)mlx_get_data_addr(data->img_east,
			&data->bpp, &data->sl, &data->endian);
	data->texture[4] = (int *)mlx_get_data_addr(data->img_weast,
			&data->bpp, &data->sl, &data->endian);
	return (1);
}

int			main(int ac, char **av)
{
	t_data			data;

	if (!ft_init(&data) || !ft_parsing(&data, av, ac)
			|| ((data.mlx_ptr = mlx_init()) == NULL)
			|| ((data.mlx_win = mlx_new_window(data.mlx_ptr,
						data.width, data.height, "cub3d")) == NULL))
	{
		ft_free(&data);
		system("killall afplay");
		return (EXIT_FAILURE);
	}
	if (!ft_init_texture(&data) || !check_bmp(ac, av, &data))
	{
		ft_free(&data);
		system("killall afplay");
		return (EXIT_FAILURE);
	}
	mlx_hook(data.mlx_win, 2, 1L << 0, &key_press, (void *)(&data));
	mlx_hook(data.mlx_win, 3, 1L << 1, &key_release, (void *)(&data));
	mlx_hook(data.mlx_win, 17, 1L << 0, &clickescape, (void *)(&data));
	mlx_loop_hook(data.mlx_ptr, &main_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
