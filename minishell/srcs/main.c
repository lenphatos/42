/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:30:32 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:59:01 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_loop(t_list_s *l, char *prec)
{
	int		i;
	char	*tmp;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		tmp = line;
		line = ft_strjoin(prec, line);
		l->back_slash_n = 0;
		if ((i = parsing(line, l)) >= 0)
			return (i);
		ft_printf("minishell$ ");
		free(line);
		free(tmp);
		line = "";
		prec = "";
	}
	if (line[0] || prec[0])
		ft_loop(l, ft_strjoin(prec, line));
	return (-1);
}

void		sigint_handler(int sig)
{
	int status;

	(void)sig;
	waitpid(-1, &status, 0);
	if (WTERMSIG(status) == SIGINT)
	{
		ft_printf("\n");
	}
	else
	{
		ft_printf("\b\b  \n");
		ft_printf("minishell$ ");
	}
}

void		sigquit_handler(int sig)
{
	int status;

	(void)sig;
	waitpid(-1, &status, 0);
	if (WTERMSIG(status) == SIGQUIT)
		ft_printf("Quit: 3\n");
	else
		ft_printf("\b\b  \b\b");
}

int			main(int ac, char **av, char **envp)
{
	int			i;
	t_list_s	l;

	i = 0;
	(void)av[ac];
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	ft_printf("minishell$ ");
	l.info = 0;
	l.path_rep = ft_split("", ':');
	l.env = ft_copy_tab(envp);
	i = ft_loop(&l, "");
	return (i);
}
