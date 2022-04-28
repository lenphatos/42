/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:42:30 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 14:42:47 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char **cmd, t_list_s *l)
{
	int i;

	i = 1;
	l->back_slash_n = 0;
	if (ft_size_array(cmd) > 1 && ft_strcmp(cmd[i], "-n") == 0)
	{
		l->back_slash_n = 1;
		i++;
	}
	while (cmd[i])
	{
		write(l->fd, cmd[i], ft_strlen(cmd[i]));
		if (cmd[i + 1] != NULL)
			write(l->fd, " ", 1);
		i++;
	}
	if (l->back_slash_n == 0)
		write(l->fd, "\n", 1);
	if (l->nbp > 0)
		exit(0);
	return (0);
}

int		ft_pwd(char **cmd, t_list_s *l)
{
	int		i;
	char	*buf;
	char	*string;

	i = 0;
	buf = NULL;
	string = NULL;
	(void)cmd;
	string = getcwd(buf, BUFFER_SIZE);
	write(l->fd, string, ft_strlen(string));
	write(l->fd, "\n", 1);
	free(string);
	if (l->nbp > 0)
		exit(0);
	return (0);
}
