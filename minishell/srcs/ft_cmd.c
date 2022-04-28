/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:06:02 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/20 16:06:04 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		***ft_take_cmd(char **tab, int *x, t_list_s *l)
{
	int		a;
	char	***cmd;

	a = 0;
	cmd = malloc(sizeof(char **) * (ft_count_pipe(tab, l) + 2));
	cmd[a++] = &tab[*x];
	while (tab[*x])
	{
		if (tab[*x][0] == '|')
		{
			free(tab[*x]);
			tab[*x] = 0;
			cmd[a++] = &tab[*x + 1];
		}
		else if (tab[*x][0] == ';')
		{
			free(tab[*x]);
			tab[(*x)++] = 0;
			cmd[a] = 0;
			return (cmd);
		}
		(*x)++;
	}
	cmd[a] = 0;
	return (cmd);
}
