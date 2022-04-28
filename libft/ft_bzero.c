/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:10:55 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:10:22 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*bzer;
	unsigned int	i;

	i = 0;
	bzer = (unsigned char*)s;
	while (i < n)
	{
		bzer[i] = '\0';
		i++;
	}
}
