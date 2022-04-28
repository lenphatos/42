/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:40:40 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/19 10:41:07 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_fork(t_philo *list)
{
	sem_wait(g_baguette);
	display_message(list, " has taken a fork\n");
	sem_wait(g_baguette);
	display_message(list, " has taken a fork\n");
}

void	clear_fork(t_philo *list)
{
	sem_post(g_baguette);
	sem_post(g_baguette);
	display_message(list, " is sleeping\n");
	ft_usleep(g_time_to_sleep * 1000);
}

void	mange(t_philo *list)
{
	sem_wait(list->lock);
	list->last_eat = gettime();
	list->limit = list->last_eat + g_time_to_die;
	display_message(list, " is eating\n");
	ft_usleep(g_time_to_eat * 1000);
	sem_post(list->must_eat_sem);
	sem_post(list->lock);

}
