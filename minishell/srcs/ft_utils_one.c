/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:18:09 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/02 17:18:10 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_strlen_pimp(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i] && str[i] != '=')
			i++;
	return (i);
}

int			ft_size_array(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			ft_count_pipe(char **tab, t_list_s *l)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (tab[i] && tab[i][0] != ';')
	{
		if (tab[i][0] == '|')
			nb++;
		i++;
	}
	l->nbp = nb;
	return (nb);
}
