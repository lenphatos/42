/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:57:12 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/12 11:03:48 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strllen(char const *str, int i, char c)
{
	int a;

	a = 0;
	while (str[i] != c && str[i])
	{
		i++;
		a++;
	}
	return (a);
}

static int		ft_count(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c) || (i == 0 && str[i] != c))
			count++;
		if (str[i] == c && str[i + 1] == '\0')
			count--;
		i++;
	}
	return (count);
}

static int		supprtout(int a, char **tab)
{
	while (--a >= 0)
		free(tab[a]);
	free(tab);
	return (1);
}

char			**ft_split(char const *str, char c)
{
	int		i;
	int		a;
	int		o;
	char	**tab;

	i = 0;
	a = 0;
	if (!str || !(tab = malloc(sizeof(char *) * (ft_count(str, c) + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!(tab[a] = malloc(sizeof(char) * (ft_strllen(str, i, c) + 1)))
		&& supprtout(a, tab))
			return (NULL);
		o = 0;
		while (str[i] != c && str[i])
			tab[a][o++] = str[i++];
		if (str[i - 1] != c)
			tab[a++][o] = '\0';
	}
	tab[a] = 0;
	return (tab);
}
