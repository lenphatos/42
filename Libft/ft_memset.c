/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:07:35 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:09:34 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mem;

	mem = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	b = (void *)mem;
	return (b);
}
