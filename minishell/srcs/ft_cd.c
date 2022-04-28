/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/07 15:37:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*parsing_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	while (path[i] != '/')
		i--;
	return (&path[++i]);
}

char		*take_actual_path(void)
{
	char	*path;
	char	*buf;
	char	*result_path;

	buf = NULL;
	result_path = NULL;
	path = getcwd(buf, BUFFER_SIZE);
	result_path = parsing_path(path);
	free(path);
	return (result_path);
}

int			ft_cd(char **cmd, t_list_s *l)
{
	(void)l;
	if ((chdir(cmd[1]) == -1))
	{
		ft_printf("bash: cd: %s: No such file or directory\n", cmd[1]);
		return (1);
	}
	return (0);
}
