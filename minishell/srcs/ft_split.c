/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/07 15:37:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_count_two(char *str)
{
	int i;

	i = 0;
	if ((str[i] == '\"' || (i && str[i - 1] == '\\')) && (i += 1))
		while (str[i] && str[i] != '\"')
			i++;
	else if ((str[i] == '\'' || (i && str[i - 1] == '\\')) && (i += 1))
		while (str[i] && (str[i] != '\'' || (i && str[i - 1] == '\\')))
			i++;
	else
		while (str[i] && ((str[i] != '\''
		&& str[i] != '\"') || (i && str[i - 1] == '\\')))
			i++;
	return (i);
}

int			ft_split_quote_fct(char *str, int i, char *tab)
{
	int k;

	k = 0;
	if (str[i] == '\"')
	{
		tab[k++] = str[i++];
		while (str[i] && (str[i] != '\"' || (i && str[i - 1] == '\\')))
			tab[k++] = str[i++];
		tab[k] = 0;
	}
	else if (str[i] == '\'')
	{
		tab[k++] = str[i++];
		while (str[i] && (str[i] != '\'' || (i && str[i - 1] == '\\')))
			tab[k++] = str[i++];
		tab[k] = 0;
	}
	if (str[i])
		i++;
	return (i);
}

char		**ft_split_quote(char *str, t_list_s *l)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	i = 0;
	if (!(tab = ft_calloc(sizeof(char *), (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		l->k = 0;
		if (!(tab[j] = ft_calloc(sizeof(char), (ft_count_two(str + i) + 1))))
			return (NULL);
		if ((str[i] == '\"' || str[i] == '\'') && (!i || str[i - 1] != '\\'))
			i = ft_split_quote_fct(str, i, tab[j++]);
		else
		{
			while (str[i] && ((str[i] != '\'' && str[i] != '\"')
			|| (i && str[i - 1] == '\\')))
				tab[j][l->k++] = str[i++];
			tab[j++][l->k] = 0;
		}
	}
	return (tab);
}
