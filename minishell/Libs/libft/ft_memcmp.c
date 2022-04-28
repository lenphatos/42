/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:34:52 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:28:32 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ts1[i] != ts2[i])
			return (ts1[i] - ts2[i]);
		i++;
	}
	return (0);
}
