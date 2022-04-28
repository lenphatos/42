/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retire_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:52:33 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:52:35 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**retire_slash_bis(char **tab)
{
	int i;
	int a;
	int b;

	i = -1;
	while (tab[++i])
	{
		a = 0;
		b = 0;
		while (tab[i][b])
		{
			if (tab[i][b] == '\\')
				b++;
			tab[i][a] = tab[i][b];
			a++;
			b++;
		}
		tab[i][a] = 0;
	}
	return (tab);
}

char	***retire_slash(char ***tab)
{
	int i;

	i = -1;
	while (tab[++i])
		tab[i] = retire_slash_bis(tab[i]);
	return (tab);
}
