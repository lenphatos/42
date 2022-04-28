/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:03:26 by simoulin          #+#    #+#             */
/*   Updated: 2021/05/12 13:31:26 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>

int				g_done;
int				g_nb_philo;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_time_to_die;
int				g_must_eat_count;
u_int64_t		g_timee;
pthread_mutex_t	*g_baguette;
pthread_mutex_t	g_dead;
pthread_mutex_t	g_writee;

typedef struct	s_philo
{
	int				count;
	int				left;
	int				right;
	int				id;
	u_int64_t		last_eat;
	u_int64_t		limit;
	pthread_mutex_t	lock;
	pthread_mutex_t	must_eat;

}				t_philo;

int				digit(char **tab);
int				exit_error(int error);
int				init_thread(void);
int				init_global(int ac, char **av);
void			ft_usleep(unsigned int n);
void			mange(t_philo *list);
void			take_fork(int left, int right, t_philo *list);
void			clear_fork(int left, int right, t_philo *list);
void			display_message(t_philo *philo, char *str);
void			*monitor_two(void *arg);
void			*monitor(void *arg);
void			*philo(void *arg);
void			start_thread(t_philo *list);
void			clear(t_philo *list);
u_int64_t		gettime();

#endif
