/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:41:46 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/29 13:42:35 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

sem_t	*my_sem_init(char *name, int state)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, state));
}

int		init_thread(void)
{
	int		i;
	t_philo	list[g_nb_philo];

	i = -1;
	g_done = 0;
	g_dead = my_sem_init("dead", 0);
	g_writee = my_sem_init("writee", 1);
	g_baguette = my_sem_init("baguette", g_nb_philo);
	while (++i < g_nb_philo)
	{
		list[i].id = i;
		list[i].is_eating = 0;
		list[i].lock = my_sem_init("lock", 1);
		list[i].must_eat_sem = my_sem_init("must_eat", 0);
	}
	start_thread(list);
	sem_wait(g_dead);
	i = 0;
	while (i < g_nb_philo)
		kill(list[i++].pid, SIGKILL);
	clear(list);
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
