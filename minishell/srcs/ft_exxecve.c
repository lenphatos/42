/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exxecve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:43:23 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 14:43:42 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			multi_cmd(char **tab, t_list_s *l)
{
	dup2(l->fd, 1);
	dup2(l->fd_t, 0);
	if (execve(l->path, tab, l->env) == -1)
		exit(127);
	return (0);
}

int			one_cmd(char **tab, t_list_s *l)
{
	int pid;
	int test;

	test = 0;
	if ((pid = fork()) == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(l->fd, 1);
		dup2(l->fd_t, 0);
		if (execve(l->path, tab, l->env) == -1)
		{
			ft_printf("bash: %s: command not found\n", tab[0]);
			exit(127);
		}
	}
	else
		wait(&test);
	test = WEXITSTATUS(test);
	return (test);
}

int			ft_exxecve(char **tab, t_list_s *l)
{
	if (l->nbp == 0)
		return (one_cmd(tab, l));
	else
		return (multi_cmd(tab, l));
	return (0);
}
