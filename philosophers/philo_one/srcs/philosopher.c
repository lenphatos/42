/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:29:43 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/12 13:31:54 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo(void *arg)
{
	pthread_t	tid;
	t_philo		*list;

	list = (t_philo *)arg;
	list->left = list->id;
	list->right = (list->left + 1) % g_nb_philo;
	list->last_eat = gettime();
	list->limit = list->last_eat + g_time_to_die;
	pthread_create(&tid, NULL, &monitor, (void *)list);
	while (1 && g_done == 0)
	{
		take_fork(list->left, list->right, list);
		mange(list);
		clear_fork(list->left, list->right, list);
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
	g_timee = gettime();
	count = g_nb_philo;
	(g_must_eat_count == 1) ? (count += 1) : 0;
	if (!(phil = (pthread_t *)malloc(sizeof(pthread_t) * count)))
		return ;
	if (g_must_eat_count)
		pthread_create(&phil[count - 1], NULL, &monitor_two, (void *)list);
	while (i < g_nb_philo)
	{
		pthread_create(&phil[i], NULL, &philo, (void *)&list[i]);
		usleep(35);
		i++;
	}
	i = 0;
	while (i < g_nb_philo)
		pthread_join(phil[i++], NULL);
	if (g_must_eat_count)
		pthread_join(phil[i++], NULL);
	free(phil);
	clear(list);
}
