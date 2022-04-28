/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:36:28 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/14 10:55:45 by simoulin         ###   ########.fr       */
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
		return ((void*)1);
	while (1 && g_done == 0)
	{
		take_fork(list);
		mange(list);
		clear_fork(list);
		display_message(list, " is thinking\n");
	}
	pthread_join(tid, NULL);
	return (NULL);
}

void	start_thread(t_philo *list)
{
	int				i;
	int				count;
	pthread_t		*phil;

	i = 0;
	count = g_nb_philo;
	(g_must_eat_count == 1) ? (count += 1) : 0;
	if (!(phil = malloc(sizeof(pthread_t) * count)))
		return ;
	if (g_must_eat_count)
		pthread_create(&phil[count - 1], NULL, &monitor_two, (void *)list);
	g_timee = gettime();
	while (i < g_nb_philo)
	{
		pthread_create(&phil[i], NULL, &philo, (void *)&list[i]);
		i++;
		usleep(35);
	}
	i = 0;
	while (i < g_nb_philo)
		pthread_join(phil[i++], NULL);
	if (g_must_eat_count)
		pthread_join(phil[i++], NULL);
	free(phil);
	clear(list);
}
