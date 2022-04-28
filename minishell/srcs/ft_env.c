/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:41:02 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 14:41:13 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_printable_env(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int			ft_env(char **cmd, t_list_s *l)
{
	int	i;

	i = -1;
	(void)cmd;
	while (l->env[++i])
		if (ft_printable_env(l->env[i]))
		{
			write(l->fd, l->env[i], ft_strlen(l->env[i]));
			write(l->fd, "\n", 1);
		}
	if (l->nbp > 0)
		exit(0);
	return (0);
}
