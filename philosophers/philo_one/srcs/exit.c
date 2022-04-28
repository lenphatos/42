/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:25:26 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/19 10:25:49 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	clear(t_philo *list)
{
	int i;

	i = -1;
	while (++i < g_nb_philo)
	{
		pthread_mutex_destroy(&g_baguette[i]);
		pthread_mutex_destroy(&list[i].lock);
		pthread_mutex_destroy(&list[i].must_eat);
	}
	pthread_mutex_destroy(&g_dead);
	pthread_mutex_destroy(&g_writee);
	free(g_baguette);
}

int		exit_error(int error)
{
	if (error == 1)
	{
		printf("Wrong number of argv\n");
		return (1);
	}
	else if (error == 2)
	{
		printf("Argv must be digit\n");
		return (1);
	}
	else if (error == 3)
	{
		printf("Wrong value of argv\n");
		return (1);
	}
	return (0);
}
