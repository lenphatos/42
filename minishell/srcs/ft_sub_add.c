/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/07 15:37:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**add_case(char **tab, int trou)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (tab[i])
		i++;
	if (!(new = malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (i == trou)
		{
			new[i] = strdup(tab[i]);
			j++;
		}
		new[i + j] = tab[i];
		i++;
	}
	new[i + j] = 0;
	free(tab);
	return (new);
}

char		**sub_case(char **tab, int trou)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (tab[i])
		i++;
	if (!(new = malloc(sizeof(char *) * (i))))
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (i == trou)
		{
			free(tab[i]);
			i++;
			continue;
		}
		new[j++] = tab[i++];
	}
	new[j] = 0;
	free(tab);
	return (new);
}
