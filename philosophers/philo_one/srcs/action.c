/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:22:48 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/12 13:21:55 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void take_fork(int left, int right, t_philo *list)
{
	pthread_mutex_lock(&g_baguette[left]);
	display_message(list, " has taken a fork\n");
	pthread_mutex_lock(&g_baguette[right]);
	display_message(list, " has taken a fork\n");
}

void clear_fork(int left, int right, t_philo *list)
{
	pthread_mutex_unlock(&g_baguette[left]);
	pthread_mutex_unlock(&g_baguette[right]);
	ft_usleep(g_time_to_sleep * 1000);
	display_message(list, " is sleeping\n");
}

void mange(t_philo *list)
{
	pthread_mutex_lock(&list->lock);
	display_message(list, " is eating\n");
	list->last_eat = gettime();
	list->limit = list->last_eat + g_time_to_die;
	ft_usleep(g_time_to_eat * 1000);
	pthread_mutex_unlock(&list->must_eat);
	pthread_mutex_unlock(&list->lock);
}
