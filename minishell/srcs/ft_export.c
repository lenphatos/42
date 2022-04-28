/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:06:06 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:44:29 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_size_malloc(char *cmd, char **env)
{
	int i;
	int nb;

	i = -1;
	nb = 2;
	while (env[++i])
		if (!(ft_strnncmp(cmd, env[i])) && (egal(env[i])
		|| (!egal(cmd) && !egal(env[i]))))
			nb = 1;
	return (nb);
}

char		**ft_put_new_env(char *cmd, t_list_s *l, int nb)
{
	int		i;
	int		j;
	int		size_malloc;
	char	**new;

	i = -1;
	j = 0;
	size_malloc = ft_size_malloc(cmd, l->env);
	if (!(new = malloc(sizeof(char *) *
	(ft_size_array(l->env) + size_malloc))))
		return (NULL);
	while (l->env[++i])
	{
		if (ft_strnncmp(cmd, l->env[i]))
			new[j++] = ft_strdup(l->env[i]);
		else if (ft_strnncmp(cmd, l->env[i]) == 0
		&& (egal(l->env[i]) && !egal(cmd)))
			new[j++] = ft_strdup(l->env[i]);
		else if (ft_strnncmp(cmd, l->env[i]) == 0)
			new[j++] = ft_strdup(cmd);
	}
	if (size_malloc == 2 && nb == 0)
		new[j++] = ft_strdup(cmd);
	new[j] = 0;
	return (new);
}

char		*ft_print_export(char *str, char *begin, char *new)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(new = malloc(sizeof(char) * i + 14)))
		return (NULL);
	i = -1;
	while (++i < 11)
		new[i] = begin[i];
	while (*str && *str != '=')
		new[i++] = *(str++);
	if (!egal(str) && (new[i++] = '\n'))
	{
		new[i] = 0;
		return (new);
	}
	new[i++] = *(str++);
	new[i++] = '"';
	while (*str)
		new[i++] = *(str++);
	new[i++] = '"';
	new[i++] = '\n';
	new[i] = 0;
	return (new);
}

void		ft_print_env(t_list_s *l)
{
	int		i;
	char	*tmp;
	char	**new;
	char	*print;
	char	*begin;

	i = -1;
	tmp = NULL;
	if (!(begin = malloc(sizeof(char) * 11)))
		return ;
	begin = ft_strcpy(begin, "declare -x ");
	new = ft_alpha_order(ft_copy_tab(l->env));
	while (new[++i])
	{
		print = ft_print_export(new[i], begin, tmp);
		write(l->fd, print, ft_strlen(print));
		free(print);
	}
	ft_free(new);
	free(begin);
	free(new);
}

int			ft_export(char **cmd, t_list_s *l)
{
	int		i;
	int		nb;
	char	**tmp;

	i = 0;
	if (cmd[1])
		while (cmd[++i])
		{
			tmp = l->env;
			nb = ft_check_new_env(cmd[i]);
			if (nb != 1 && !(l->env = ft_put_new_env(cmd[i], l, nb)))
				return (1);
			ft_free(tmp);
			free(tmp);
		}
	else
		ft_print_env(l);
	if (l->nbp > 0)
		exit(0);
	return (0);
}
