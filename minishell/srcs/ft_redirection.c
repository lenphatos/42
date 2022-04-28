/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/07 15:37:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		decale2(char **tab)
{
	int i;

	i = 0;
	if (tab[i])
		free(tab[i]);
	if (tab[i + 1])
		free(tab[i + 1]);
	while (tab[i] && tab[i + 1])
	{
		tab[i] = tab[i + 2];
		i++;
	}
	if (tab[i])
	{
		tab[i + 1] = NULL;
		tab[i] = NULL;
	}
}

char		**ft_redirection(char **tab, t_list_s *l)
{
	int i;

	i = -1;
	l->fd = 1;
	l->fd_t = 0;
	while (tab[++i])
	{
		if (tab[i][0] == '>')
		{
			if (tab[i][1] == '>')
				l->fd = open(tab[i + 1], O_APPEND | O_WRONLY | O_CREAT);
			else
				l->fd = open(tab[i + 1], O_TRUNC | O_WRONLY | O_CREAT);
			decale2(tab + i);
			i -= 1;
		}
		else if (tab[i][0] == '<')
		{
			l->fd_t = open(tab[i + 1], O_RDONLY);
			decale2(tab + i);
			i -= 1;
		}
	}
	return (tab);
}
