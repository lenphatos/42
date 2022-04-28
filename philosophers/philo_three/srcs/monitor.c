/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:42:26 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/29 13:40:07 by simoulin         ###   ########.fr       */
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
	while (++end < g_must_eat_count)
	{
		i = -1;
		while (++i < g_nb_philo)
			sem_wait(list[i].must_eat_sem);
	}
	display_message(list, "must count reached\n");
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*list;

	list = (t_philo *)arg;
	while (1)
	{
		sem_wait(list->lock);
		if (!list->is_eating && gettime() > list->limit)
		{
			display_message(list, " died\n");
			return (NULL);
		}
		sem_post(list->lock);
		ft_usleep(100);
	}
	return (NULL);
}
