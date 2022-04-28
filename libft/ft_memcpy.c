/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:24:21 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:11:29 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tempdst;
	unsigned char	*tempsrc;
	size_t			i;

	i = 0;
	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	if (src == NULL && dst == NULL)
		return (0);
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}
