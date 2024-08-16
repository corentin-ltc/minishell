/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:56:50 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/13 17:40:57 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_content;
	t_list	*new_node;

	map = NULL;
	while (lst && f && del)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_node);
		lst = lst->next;
	}
	return (map);
}
