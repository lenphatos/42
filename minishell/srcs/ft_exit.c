/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 11:34:43 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_error_bis(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i + 1] && ((tab[i][0] == ';' && tab[i + 1][0] == '|')
		|| (tab[i][0] == '|' && tab[i + 1][0] == ';')
		|| (tab[i][0] == '|' && tab[i + 1][0] == '|')))
		{
			ft_printf("bash: syntax error near unexpected token `%c'\n",
					tab[i + 1][0]);
			return (0);
		}
		if ((tab[i][0] == '<' || tab[i][0] == '>' || tab[i][0] == '|')
		&& tab[i + 1] == NULL)
		{
			ft_printf("bash: syntax error near unexpected token `%c'\n",
					tab[i + 1][0]);
			return (0);
		}
	}
	return (1);
}

int			check_error(char **tab, t_list_s *l)
{
	if (tab[0][0] == ';'
	|| (tab[0][0] == '<' && tab[1] == NULL)
	|| (tab[0][0] == '<' && tab[1][0] == '<' && tab[2] == NULL)
	|| tab[0][0] == '>' || tab[0][0] == '|')
	{
		ft_printf("bash: syntax error near unexpected token `%c'\n",
				tab[0][0]);
		l->info = 258;
		return (0);
	}
	else if (check_error_bis(tab) == 0)
	{
		l->info = 258;
		return (0);
	}
	return (1);
}

int			error_exit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+') && str[i + 1])
			i++;
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}

int			ft_exit(char **cmd)
{
	ft_printf("exit\n");
	if (cmd[1])
	{
		if (error_exit(cmd[1]) == 0)
		{
			ft_printf("bash: exit: %s: numeric argument required\n",
					cmd[1]);
			return (255);
		}
		else
		{
			if (cmd[2])
			{
				ft_printf("bash: exit: too many arguments\n");
				return (-2);
			}
		}
		return ((unsigned char)ft_atoi(cmd[1]));
	}
	return (0);
}
