/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:47:31 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:12:36 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	i = 0;
	if (tdst == NULL && tsrc == NULL)
		return (0);
	if (tsrc < tdst)
		while (i < len)
		{
			i++;
			tdst[len - i] = tsrc[len - i];
		}
	else
		while (i < len)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	return (dst);
}
