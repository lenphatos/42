/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:58:35 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/08 19:42:55 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		a;
	int		count;
	char	*str;

	i = 0;
	a = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i])
		i++;
	while (ft_check(s1[a], set) != 0 && a < i)
		a++;
	i -= 1;
	while (ft_check(s1[i], set) != 0 && i > 0)
		i--;
	count = (i > a ? (i - a + 2) : 1);
	if (!(str = malloc(sizeof(char) * count)))
		return (0);
	i = 0;
	while (i < count - 1)
		str[i++] = s1[a++];
	str[i] = '\0';
	return (str);
}
