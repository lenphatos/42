/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:49:03 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:54:15 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextone;
	t_list	*todel;

	todel = *lst;
	while (todel)
	{
		nextone = todel->next;
		del(todel->content);
		free(todel);
		todel = nextone;
	}
	*lst = NULL;
}
