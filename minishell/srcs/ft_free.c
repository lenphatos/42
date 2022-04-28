/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:46:10 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:46:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_freeee(char **tab, char **path_rep, char ***cmd, int x)
{
	if (x != -2)
	{
		free(tab);
		ft_free(path_rep);
		free(path_rep);
	}
	ft_free(tab);
	free(cmd);
}

void		ft_free(char **line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		free(line[i]);
		line[i] = NULL;
	}
}

void		ft_free_tab(char **line, int x)
{
	x--;
	while (x >= 0)
	{
		free(line[x]);
		line[x--] = NULL;
	}
}

void		ft_free_cmd(char ***cmd)
{
	int	i;
	int	a;

	i = -1;
	while (cmd[++i])
	{
		a = -1;
		while (cmd[i][++a])
		{
			free(cmd[i][a]);
			cmd[i][a] = NULL;
		}
		free(cmd[i]);
	}
}
