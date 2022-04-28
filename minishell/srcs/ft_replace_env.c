/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:36:48 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/07 15:37:11 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*replace_env_two(char *s, char *s1, char *s2, t_list_s *l)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 1;
	(s1[1] == '?') ? (j = 2) : 0;
	(s1[1] == '?') ? (i = -1) : 0;
	if (s1[1] != '?')
	{
		while (s2[i] && s2[i] != '=')
			i++;
		while (ft_isalnum(s1[j]) || s1[j] == '_')
			j++;
	}
	s1[0] = 0;
	ret = s;
	if (s2[0])
		ret = ft_strjoin(s, s2 + i + 1);
	l->tmp = ret;
	ret = ft_strjoin(ret, s1 + j);
	if (s2[0])
		free(s);
	free(l->tmp);
	return (ret);
}

char		*ft_replace_env_bis(char **tab, int i, int a, t_list_s *l)
{
	int		j;
	char	*trouve;

	if (tab[i][a + 1] == '?')
	{
		trouve = ft_itoa(l->info);
		tab[i] = replace_env_two(tab[i], tab[i] + a, trouve, l);
		free(trouve);
	}
	else if (tab[i][a + 1])
	{
		j = -1;
		trouve = "";
		while (l->env[++j])
			if (ft_strcmp_p(tab[i] + a + 1, l->env[j]))
				trouve = l->env[j];
		tab[i] = replace_env_two(tab[i], tab[i] + a, trouve, l);
	}
	return (tab[i]);
}

char		**ft_replace_env(char **tab, t_list_s *l)
{
	int	i;
	int	a;

	i = -1;
	l->tmp = NULL;
	while (tab[++i])
		if (tab[i][0] != '\'')
		{
			a = -1;
			while (tab[i][++a])
				if (tab[i][a] == '$' && (!a || tab[i][a - 1] != '\\'))
					tab[i] = ft_replace_env_bis(tab, i, a, l);
		}
	return (tab);
}
