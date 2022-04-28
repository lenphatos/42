/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:26:26 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/11 11:44:39 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int		init_thread(void)
{
	int			i;
	t_philo		list[g_nb_philo];

	i = -1;
	if (!(g_baguette = malloc(sizeof(pthread_mutex_t) * g_nb_philo)))
		return (0);
	pthread_mutex_init(&g_dead, NULL);
	pthread_mutex_init(&g_writee, NULL);
	while (++i < g_nb_philo)
	{
		list[i].id = i;
		pthread_mutex_init(&g_baguette[i], NULL);
		pthread_mutex_init(&list[i].lock, NULL);
		pthread_mutex_init(&list[i].must_eat, NULL);
	}
	start_thread(list);
	return (0);
}

int		init_global(int ac, char **av)
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
