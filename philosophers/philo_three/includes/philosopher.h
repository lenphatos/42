/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:46:43 by simoulin          #+#    #+#             */
/*   Updated: 2021/04/19 10:54:57 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <fcntl.h>
# include <signal.h>

int				g_done;
int				g_nb_philo;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_time_to_die;
int				g_must_eat_count;
u_int64_t		g_timee;
sem_t			*g_dead;
sem_t			*g_writee;
sem_t			*g_baguette;

typedef struct	s_philo
{
	int			pid;
	int			id;
	int			count;
	int			is_eating;
	u_int64_t	last_eat;
	u_int64_t	limit;
	sem_t		*lock;
	sem_t		*must_eat_sem;
}				t_philo;

int				digit(char **tab);
int				exit_error(int error);
int				init_thread(void);
int				init_global(int ac, char **av);
void			ft_usleep(unsigned int n);
void			mange(t_philo *list);
void			take_fork(t_philo *list);
void			clear_fork(t_philo *list);
void			display_message(t_philo *philo, char *str);
void			*monitor_two(void *arg);
void			*monitor(void *arg);
void			*philo(void *arg);
void			start_thread(t_philo *list);
void			clear(t_philo *list);
u_int64_t		gettime();

#endif
