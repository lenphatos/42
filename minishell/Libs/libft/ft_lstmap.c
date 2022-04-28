/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:06:10 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:55:43 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*prems;

	if (!lst)
		return (0);
	if (!(newlist = ft_lstnew((*f)(lst->content))))
		return (0);
	prems = newlist;
	while (lst->next)
	{
		if (!(newlist->next = ft_lstnew((*f)(lst->next->content))))
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (prems);
}
