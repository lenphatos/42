/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:28:33 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/04 11:45:50 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_recup_map(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] != '1' && str[i] != ' ')
			return (0);
	if (i == 0)
		return (0);
	return (1);
}

char	*ft_nospace_m(char *str, int lenmax)
{
	int		i;
	char	*nospace;
	int		j;

	j = 0;
	i = -1;
	if (!(nospace = malloc(sizeof(char) * (lenmax))))
		return (NULL);
	while (str[++i])
	{
		if (str[i] == ' ')
			nospace[j++] = '#';
		else
			nospace[j++] = str[i];
		lenmax--;
	}
	while (lenmax--)
		nospace[j++] = '#';
	nospace[j] = '\0';
	return (nospace);
}
