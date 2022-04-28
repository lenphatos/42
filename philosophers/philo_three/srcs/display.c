/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:41:11 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/14 11:01:42 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	display_message(t_philo *philo, char *str)
{
	sem_wait(g_writee);
	if (!g_done)
	{
		if (!strcmp(str, "must count reached\n"))
		{
			printf("%llu	%d %s", gettime() - g_timee, philo->id + 1, str);
			sem_post(g_dead);
			return ;
		}
		else if (!strcmp(str, " died\n"))
		{
			printf("%llu	%d %s", gettime() - g_timee, philo->id + 1, str);
			sem_post(g_dead);
			return ;
		}
		else
			printf("%llu	%d %s", gettime() - g_timee, philo->id + 1, str);
	}
	sem_post(g_writee);
}
