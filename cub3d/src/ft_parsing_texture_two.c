/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:09:51 by simoulin          #+#    #+#             */
/*   Updated: 2020/01/22 16:31:30 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*ft_path_sprite(char *str)
{
	int		i;
	char	*tab;

	i = 1;
	tab = NULL;
	if (str[i] != ' ')
		return (NULL);
	while (str[i] == ' ')
		i++;
	tab = &str[i];
	return (tab);
}

char			*ft_path_north(char *str)
{
	int		i;
	char	*tab;

	i = 2;
	tab = NULL;
	if (str[i] != ' ')
		return (NULL);
	while (str[i] == ' ')
		i++;
	if (str[i] != ' ')
		tab = &str[i];
	return (tab);
}

char			*ft_path_south(char *str)
{
	int		i;
	char	*tab;

	i = 2;
	tab = NULL;
	if (str[i] != ' ')
		return (NULL);
	while (str[i] == ' ')
		i++;
	if (str[i] != ' ')
		tab = &str[i];
	return (tab);
}

char			*ft_path_east(char *str)
{
	int		i;
	char	*tab;

	i = 2;
	tab = NULL;
	if (str[i] != ' ')
		return (NULL);
	while (str[i] == ' ')
		i++;
	if (str[i] != ' ')
		tab = &str[i];
	return (tab);
}

char			*ft_path_weast(char *str)
{
	int		i;
	char	*tab;

	i = 2;
	tab = NULL;
	if (str[i] != ' ')
		return (NULL);
	while (str[i] == ' ')
		i++;
	if (str[i] != ' ')
		tab = &str[i];
	return (tab);
}
