/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:41:28 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/29 13:41:16 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	clear(t_philo *list)
{
	int i;

	i = -1;
	(void)list;
	sem_close(g_dead);
	sem_close(g_baguette);
	while (++i < g_nb_philo)
	{
		sem_post(list[i].must_eat_sem);
		sem_close(list[i].lock);
		sem_close(list[i].must_eat_sem);
	}
	g_done = 1;
	sem_post(g_writee);
	sem_close(g_writee);
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
