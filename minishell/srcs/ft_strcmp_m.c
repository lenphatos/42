/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strcmp_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/07 15:37:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_strcmp_p(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((ft_isalnum(s1[i]) || s1[i] == '_') && s1[i] == s2[i])
		i++;
	if (!(ft_isalnum(s1[i]) || s1[i] == '_') && s2[i] == '=')
		return (1);
	return (0);
}

int			ft_strnncmp(char *cmd, char *s2)
{
	int i;

	i = 0;
	while (cmd[i] && s2[i] && cmd[i] == s2[i]
		&& cmd[i + 1] != '=' && s2[i + 1] != '=')
		i++;
	return (cmd[i] - s2[i]);
}

int			ft_strcmp_char(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i + 1] != '=' && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
