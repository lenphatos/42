/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:40:47 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/02 17:40:49 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_search_env(char **env, char *str, t_list_s *l)
{
	int i;

	i = -1;
	while (env[++i])
	{
		if ((ft_strcmp_char(env[i], str) == 0) &&
				(ft_strcmp_char("0=", str) == 0))
		{
			l->unset_0 = -1;
			return (-1);
		}
		if (ft_strcmp_char(env[i], str) == 0 &&
				(ft_strlen_pimp(env[i]) == ft_strlen_pimp(str)))
			return (i);
	}
	return (-1);
}

char		**ft_suppr_env(char **env, int nl)
{
	int		i;
	int		a;
	int		size_malloc;
	char	**dst;

	i = 0;
	a = 0;
	dst = NULL;
	size_malloc = 0;
	(nl == -1) ? (size_malloc = 1) : 0;
	if (!(dst = malloc(sizeof(char *) * (ft_size_array(env) + size_malloc))))
		return (NULL);
	while (env[i])
	{
		if (i != nl)
			dst[a++] = ft_strdup(env[i++]);
		else
			i++;
	}
	dst[a] = 0;
	return (dst);
}

int			ft_unset(char **cmd, t_list_s *l)
{
	int		i;
	int		nl;
	char	**tmp;

	i = 0;
	if (cmd[1] != '\0')
		while (cmd[++i])
		{
			tmp = l->env;
			if ((nl = ft_search_env(l->env, cmd[i], l)) != 0)
				l->env = ft_suppr_env(l->env, nl);
			ft_free(tmp);
			free(tmp);
		}
	return (0);
}
