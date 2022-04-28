/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:23:26 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/14 10:57:37 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	display_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&g_writee);
	if (!g_done)
	{
		if (!strcmp(str, "must count reached\n"))
		{
			g_done = 1;
			printf("%llu	%d %s", gettime() - g_timee, philo->id + 1, str);
		}
		else if (!strcmp(str, " died\n"))
		{
			g_done = 1;
			printf("%llu	%d %s", gettime() - g_timee, philo->id + 1, str);
		}
		else
			printf("%llu	%d %s", gettime() - g_timee, philo->id + 1, str);
	}
	pthread_mutex_unlock(&g_writee);
}
