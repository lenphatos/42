/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:27:18 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/12 13:20:53 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*monitor_two(void *arg)
{
	int		end;
	int		i;
	t_philo	*list;

	end = -1;
	list = (t_philo *)arg;
	while (++end <= g_must_eat_count)
	{
		i = -1;
		while (++i < g_nb_philo)
			pthread_mutex_lock(&list[i].must_eat);
	}
	display_message(list, "must count reached\n");
	pthread_mutex_unlock(&g_dead);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*list;

	list = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&list->lock);
		if (gettime() > list->limit)
		{
			display_message(list, " died\n");
			pthread_mutex_unlock(&list->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&list->lock);
		ft_usleep(100);
	}
	return (NULL);
}
