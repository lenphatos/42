/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:06:02 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 12:03:31 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_find_cmd(t_list_s *l, char **tab)
{
	int				i;
	char			*tmp;
	struct stat		buf;

	i = 0;
	l->path = ft_strjoin("", tab[0]);
	if ((stat(tab[0], &buf) >= 0)
	&& (buf.st_mode > 0) && (S_IEXEC & buf.st_mode))
		return (0);
	if (l->path_rep[0])
		free(l->path);
	while (l->path_rep[i])
	{
		l->path = ft_strjoin(l->path_rep[i], "/");
		tmp = l->path;
		l->path = ft_strjoin(l->path, tab[0]);
		free(tmp);
		if ((stat(l->path, &buf) >= 0)
		&& (buf.st_mode > 0) && (S_IEXEC & buf.st_mode))
			return (0);
		free(l->path);
		l->path = NULL;
		i++;
	}
	return (1);
}

void	ft_son(char ***cmd, t_list_s *l, int fd_in)
{
	dup2(fd_in, 0);
	if (*(cmd + 1) != NULL)
		dup2(l->pipe[1], 1);
	close(l->pipe[0]);
	if ((l->info = cut_spaces_builts(*cmd, l)) == 1)
		exit(127);
}

int		loop_multi_pipe(char ***cmd, t_list_s *l, int test, int fd_in)
{
	pid_t		pid;

	while (*cmd)
	{
		*cmd = ft_redirection(*cmd, l);
		pipe(l->pipe);
		if ((ft_find_cmd(l, *cmd)) && (ft_strcmp(*cmd[0], "exit")) &&
		(ft_strcmp(*cmd[0], "export")) && (ft_strcmp(*cmd[0], "unset")))
			ft_printf("bash: %s: command not found\n", *cmd[0]);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			ft_son(cmd, l, fd_in);
		else
		{
			wait(&test);
			free(l->path);
			l->info = WEXITSTATUS(test);
			close(l->pipe[1]);
			fd_in = l->pipe[0];
			cmd++;
		}
	}
	return (1);
}

int		loop_pipe(char ***cmd, t_list_s *l)
{
	int			test;
	int			fd_in;

	test = 0;
	fd_in = 0;
	if (l->nbp == 0)
	{
		*cmd = ft_redirection(*cmd, l);
		ft_find_cmd(l, *cmd);
		if (((l->info = cut_spaces_builts(*cmd, l)) == -1))
		{
			free(l->path);
			return (0);
		}
		free(l->path);
		return (1);
	}
	return (loop_multi_pipe(cmd, l, test, fd_in));
}
