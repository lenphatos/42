/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:10:44 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/12 11:06:16 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstart;
	size_t			i;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		if (!(newstart = (char *)malloc(sizeof(char) * 1)))
			return (0);
		newstart[0] = '\0';
		return (newstart);
	}
	if (!(newstart = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		newstart[i] = s[start + i];
		i++;
	}
	newstart[i] = '\0';
	return (newstart);
}
