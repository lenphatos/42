/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:04:30 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 11:35:55 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_array(t_data *data, char *av)
{
	int		fd;
	int		i;
	int		ret;
	int		count;
	char	buf[BUFFER_SIZE];

	i = 0;
	count = 0;
	if (ft_check_cub(av) == 0)
		return (0);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buf, BUFFER_SIZE) > 0))
		if (buf[0] == '\n')
			count++;
	if (close(fd) == -1)
		return (0);
	if (!(data->folder = malloc(sizeof(char *) * (count + 1))))
		return (0);
	fd = open(av, O_RDONLY);
	while ((get_next_line(fd, &data->folder[i]) > 0))
		i++;
	data->folder[i++] = 0;
	return (1);
}

void			ft_position_dev(t_data *data, char c, int y, int x)
{
	data->posy = y * 64 + 32;
	data->posx = x * 64 + 32;
	if (c == 'N')
		data->deviation = 60.1;
	if (c == 'S')
		data->deviation = -120.1;
	if (c == 'E')
		data->deviation = -30.1;
	if (c == 'W')
		data->deviation = 150.1;
}

static int		ft_position(t_data *data)
{
	int	y;
	int	x;
	int count;

	y = -1;
	count = 0;
	while (data->tab[++y])
	{
		x = -1;
		while (data->tab[y][++x])
			if (data->tab[y][x] == 'N' || data->tab[y][x] == 'S'
			|| data->tab[y][x] == 'W' || data->tab[y][x] == 'E')
			{
				count++;
				ft_position_dev(data, data->tab[y][x], y, x);
			}
	}
	if (count != 1)
	{
		ft_putstr("Error\n->player problem<-\n");
		return (0);
	}
	return (1);
}

static int		ft_decoupe(t_data *data)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (data->folder[++i])
	{
		if (data->folder[i][0] == 'R' || data->folder[i][0] == 'N'
		|| data->folder[i][0] == 'S' || data->folder[i][0] == 'W'
		|| data->folder[i][0] == 'E' || data->folder[i][0] == 'F'
		|| data->folder[i][0] == 'C')
			data->path[j++] = data->folder[i];
		else if (ft_recup_map(data->folder[i]) == 1)
		{
			data->map = &data->folder[i];
			data->path[j] = 0;
			return (1);
		}
		else if (data->folder[i][0] != '\0' && data->folder[i][0] != '\n')
		{
			ft_putstr("Error\n->bad arguments<-\n");
			return (0);
		}
	}
	return (1);
}

int				ft_parsing(t_data *data, char **av, int ac)
{
	if (ac < 2 || !ft_array(data, av[1]) || !ft_number_element(data)
	|| !ft_decoupe(data) || (data->map == 0) || !ft_locate(data)
	|| !ft_check_map(data) || !ft_position(data) || !ft_size(data))
	{
		if (data->cheror[0] == 1)
			ft_putstr("Error\n->wrong numbers of arguments<-\n");
		else if (data->map == 0 && data->index == 0)
			ft_putstr("Error\n->where is the map ?<-\n");
		return (0);
	}
	if (!ft_resolution(data) || data->height <= 0
	|| data->width <= 0)
	{
		ft_putstr("Error\n->resolution<-\n");
		return (0);
	}
	(data->width > 2560) ? data->width = 2560 : 0;
	(data->height > 1440) ? data->height = 1440 : 0;
	ft_regul(data, av, ac);
	return (1);
}
