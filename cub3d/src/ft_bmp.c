/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:00:41 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/28 14:39:49 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int			write_bmp_header(int fd, t_data *data, int filesize)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	bmpfileheader[3] = (unsigned char)(1);
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	set_int_in_char(bmpfileheader + 18, data->width);
	set_int_in_char(bmpfileheader + 22, data->height);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	set_int_in_char(bmpfileheader + 34, filesize - 54);
	set_int_in_char(bmpfileheader + 38, 2834);
	set_int_in_char(bmpfileheader + 42, 2834);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	get_color(t_data *data, int x, int y)
{
	int	color;

	color = data->addr[(int)data->width * ((int)data->height - 1 - y) + x];
	return (color & 0xFFFFFF);
}

int			write_bmp_data(int file, t_data *data, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)data->height)
	{
		j = 0;
		while (j < (int)data->width)
		{
			color = get_color(data, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			save_bmp(t_data *data)
{
	int	fd;
	int	filesize;
	int	pad;

	pad = (4 - ((int)data->width * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)data->width + pad) * (int)data->height);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT
								| O_TRUNC, 0666 | O_APPEND)) < 0)
		return (0);
	if (!write_bmp_header(fd, data, filesize))
		return (0);
	if (!write_bmp_data(fd, data, pad))
		return (0);
	close(fd);
	return (1);
}
