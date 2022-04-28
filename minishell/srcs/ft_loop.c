/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:47:02 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:47:04 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			cut_spaces_builts(char **cmd, t_list_s *l)
{
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, l));
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (ft_echo(cmd, l));
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (ft_export(cmd, l));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (ft_unset(cmd, l));
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (ft_env(cmd, l));
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (ft_pwd(cmd, l));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (-1);
	return (ft_exxecve(cmd, l));
}

int			loop(char **tab, char ***cmd, t_list_s *l, int x)
{
	char **tmp;

	while (tab[x])
	{
		cmd = ft_take_cmd(tab, &x, l);
		cmd = retire_quote(cmd);
		cmd = retire_slash(cmd);
		tmp = l->path_rep;
		l->path_rep = init_env(l->env, l);
		ft_free(tmp);
		free(tmp);
		if (loop_pipe(cmd, l) == 0)
		{
			x = ft_exit(cmd[0]);
			(x == -2) ? (l->info = 1) : 0;
			free(cmd);
			ft_free(tab);
			free(tab);
			return (x);
		}
		free(cmd);
		ft_free_tab(tab, x);
	}
	free(tab);
	return (-1);
}

char		**ft_tab(char *str, char **tab, t_list_s *l)
{
	tab = ft_split_quote(str, l);
	tab = retire_pv(tab, ";");
	tab = retire_pv(tab, "<");
	tab = retire_pv(tab, "<<");
	tab = retire_pv(tab, ">>");
	tab = retire_pv(tab, ">");
	tab = retire_pv(tab, "|");
	tab = retire_pv(tab, " ");
	tab = ft_replace_env(tab, l);
	tab = fusionne_quote(tab);
	tab = retire_pv_esp(tab);
	return (tab);
}

int			parsing(char *str, t_list_s *l)
{
	int		x;
	char	**tab;
	char	***cmd;

	x = 0;
	tab = NULL;
	cmd = NULL;
	if (!str[0] || ft_strchr(str, 27))
		return (-1);
	tab = ft_tab(str, tab, l);
	if (!tab[0] || check_error(tab, l) == 0)
	{
		ft_printf("1\n");
		ft_free(tab);
		free(tab);
		return (-1);
	}
	if (!tab[0])
		return (-1);
	return (loop(tab, cmd, l, x));
}
