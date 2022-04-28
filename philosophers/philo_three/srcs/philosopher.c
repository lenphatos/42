/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:43:02 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/29 13:12:55 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo(void *arg)
{
	pthread_t	tid;
	t_philo		*list;

	list = (t_philo *)arg;
	list->last_eat = gettime();
	list->limit = list->last_eat + g_time_to_die;
	if (pthread_create(&tid, NULL, &monitor, (void *)list) != 0)
		return ((void *)1);
	pthread_detach(tid);
	while (1)
	{
		take_fork(list);
		mange(list);
		clear_fork(list);
		display_message(list, " is thinking\n");
	}
	return (NULL);
}

void	start_thread(t_philo *list)
{
	int			i;
	pthread_t	phil;

	i = -1;
	g_timee = gettime();
	if (g_must_eat_count)
	{
		pthread_create(&phil, NULL, &monitor_two, (void *)list);
		pthread_detach(phil);
	}
	while (++i < g_nb_philo)
	{
		list[i].pid = fork();
		if (list[i].pid < 0)
			return ;
		else if (list[i].pid == 0)
		{
			philo((void *)&list[i]);
			exit(0);
		}
		usleep(35);
	}
}
