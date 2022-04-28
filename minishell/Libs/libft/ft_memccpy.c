/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:04:34 by fde-fram          #+#    #+#             */
/*   Updated: 2019/11/13 16:35:40 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (tmpsrc[i] == (unsigned char)c)
		{
			tmpdst[i] = tmpsrc[i];
			return ((void *)&dst[i + 1]);
		}
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (0);
}
