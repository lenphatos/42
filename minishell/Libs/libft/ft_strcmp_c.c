/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:40:55 by simoulin          #+#    #+#             */
/*   Updated: 2020/03/06 12:44:02 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

int	ft_strcmp_c(const char *s1, const char *s2, char c)
{
	unsigned int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] != c && s2[i] != c
			&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return (!((!s2[i] || s2[i] == c) && s1[i] == c));
}
