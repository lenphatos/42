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

int			ft_check_new_env(char *cmd)
{
	int i;

	i = -1;
	if (cmd[0] == '=')
	{
		ft_printf("Minishell: export: `%s': not a valid identifier\n", cmd);
		return (1);
	}
	while (cmd[++i] && cmd[i] != '=')
		if ((cmd[0] >= '0' && cmd[0] <= '9')
		|| (cmd[i] < '0' || (cmd[i] > '9' && cmd[i] < 'A')
		|| (cmd[i] > 'Z' && cmd[i] < 'a') || cmd[i] > 'z'))
		{
			ft_printf("Minishell: export: `%s': not a valid identifier\n", cmd);
			return (1);
		}
	return (0);
}

int			egal(char *cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
		if (cmd[i] == '=')
			return (1);
	return (0);
}

char		**ft_alpha_order(char **env)
{
	int		i;
	int		nb;
	char	*str;

	i = 0;
	nb = ft_size_array(env);
	while (i < (nb - 1))
	{
		if (ft_strcmp(env[i], env[i + 1]) > 0)
		{
			str = env[i];
			env[i] = env[i + 1];
			env[i + 1] = str;
			i = 0;
		}
		i++;
	}
	return (env);
}

char		**ft_copy_tab(char **env)
{
	int		i;
	char	**dst;

	i = 0;
	dst = NULL;
	if (!(dst = (char**)malloc(sizeof(char *) * (ft_size_array(env) + 1))))
		return (NULL);
	while (env[i])
	{
		dst[i] = ft_strdup(env[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
