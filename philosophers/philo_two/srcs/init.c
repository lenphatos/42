/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:35:34 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/12 13:33:59 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_thread(void)
{
	int		i;
	t_philo	list[g_nb_philo];

	i = -1;
	sem_unlink("dead");
	sem_unlink("baguette");
	sem_unlink("writee");
	g_dead = NULL;
	g_writee = NULL;
	g_baguette = NULL;
	g_done = 0;
	g_dead = sem_open("dead", O_CREAT | O_EXCL, 0644, 0);
	g_writee = sem_open("writee", O_CREAT | O_EXCL, 0644, 1);
	g_baguette = sem_open("baguette", O_CREAT | O_EXCL, 0644, g_nb_philo);
	while (++i < g_nb_philo)
	{
		list[i].id = i;
		sem_unlink("lock");
		list[i].lock = sem_open("lock", O_CREAT, 0600, 1);
		sem_unlink("lock");
		list[i].must_eat_sem = sem_open("lock", O_CREAT, 0600, 0);
	}
	start_thread(list);
	return (0);
}

int	init_global(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (exit_error(1));
	if (digit(&av[1]))
		return (exit_error(2));
	else
	{
		g_nb_philo = atoi(av[1]);
		g_time_to_die = atoi(av[2]);
		g_time_to_eat = atoi(av[3]);
		g_time_to_sleep = atoi(av[4]);
		g_must_eat_count = 0;
		if (ac == 6)
			g_must_eat_count = atoi(av[5]);
		if (g_nb_philo < 2 || g_nb_philo > 200 || g_time_to_die < 60
				|| g_time_to_eat < 60 || g_time_to_sleep < 60
				|| g_must_eat_count < 0)
			return (exit_error(3));
	}
	return (0);
}
