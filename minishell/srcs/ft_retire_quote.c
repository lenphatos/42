/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retire_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:51:09 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:51:10 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**fusionne_quote(char **tab)
{
	int		a;
	char	*tmp;

	a = 0;
	while (tab[a] && tab[a + 1])
	{
		if ((tab[a][0] != '<' && tab[a][0] != '>' && tab[a][0] != '|'
		&& tab[a][0] != ' ' && tab[a][0] != ';')
		&& (tab[a + 1][0] != '<' && tab[a + 1][0] != '>'
		&& tab[a + 1][0] != '|' && tab[a + 1][0] != ' '
		&& tab[a + 1][0] != ';'))
		{
			tmp = tab[a];
			tab[a] = ft_strjoin(tab[a], tab[a + 1] + (tab[a + 1][0] == '\'' ||
						tab[a + 1][0] == '"'));
			free(tmp);
			tab = sub_case(tab, a + 1);
			a--;
		}
		a++;
	}
	return (tab);
}

char		***retire_quote(char ***tab)
{
	int		i;
	int		a;
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		a = 0;
		while (tab[i][a])
		{
			if (tab[i][a][0] == '\'' || tab[i][a][0] == '"')
			{
				tmp = tab[i][a];
				tab[i][a] = ft_strdup(tab[i][a] + 1);
				free(tmp);
			}
			a++;
		}
	}
	return (tab);
}
