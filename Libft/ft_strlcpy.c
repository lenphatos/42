/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <fde-fram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:46:16 by fde-fram          #+#    #+#             */
/*   Updated: 2019/11/13 16:27:34 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t index;

	i = 0;
	index = 0;
	if (src == NULL)
		return (0);
	while (src[index])
		index++;
	if (dstsize > 1)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (dstsize >= 1)
		dst[i] = '\0';
	return (index);
}
