/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retire_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:06:02 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/20 16:06:04 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**retir_pv_utils(char **tab, int i, int j, char *c)
{
	char	*tmp;

	if (tab[i][j + strlen(c)])
	{
		tab = add_case(tab, i);
		tab[i][j + strlen(c)] = 0;
		tmp = tab[i + 1];
		tab[i + 1] = ft_strdup(tab[i + 1] + j + strlen(c));
		free(tmp);
	}
	if (j)
	{
		tab = add_case(tab, i);
		tab[i][j] = 0;
		tmp = tab[i + 1];
		tab[i + 1] = ft_strdup(tab[i + 1] + j);
		free(tmp);
	}
	return (tab);
}

char		**retire_pv(char **tab, char *c)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		if (tab[i][0] != '"' && tab[i][0] != '\'' && strcmp(tab[i], ">>"))
			while (tab[i][++j])
				if (!strncmp(tab[i] + j, c, strlen(c))
				&& (!j || tab[i][j - 1] != '\\'))
					tab = retir_pv_utils(tab, i, j, c);
	}
	return (tab);
}

char		**retire_pv_esp(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == ' ' && !tab[i][1])
			tab = sub_case(tab, i);
		else
			i++;
	}
	return (tab);
}
