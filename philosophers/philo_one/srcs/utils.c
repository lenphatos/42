/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:31:24 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/12 13:32:38 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

u_int64_t	gettime(void)
{
	static struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int			digit(char **tab)
{
	int	i;
	int	x;

	i = -1;
	while (tab[++i])
	{
		x = -1;
		while (tab[i][++x])
			if (tab[i][x] < '0' || tab[i][x] > '9')
				return (1);
	}
	return (0);
}

void		ft_usleep(unsigned int n)
{
	struct timeval	start;
	struct timeval	step;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&step, NULL);
		if ((size_t)(((size_t)(step.tv_sec - start.tv_sec)) * 1000000 +
					((size_t)(step.tv_usec - start.tv_usec))) > n)
			break ;
	}
}
