/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:00:29 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/24 12:00:30 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**init_env(char **env, t_list_s *l)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	(void)l;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH", 4) == 0 && (j = 1))
			l->path_rep = ft_split(&env[i][5], ':');
	if (j == 0)
		l->path_rep = ft_split("", ':');
	return (l->path_rep);
}
