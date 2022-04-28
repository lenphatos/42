/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:11 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:25:47 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned	int i;
	unsigned	int j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
