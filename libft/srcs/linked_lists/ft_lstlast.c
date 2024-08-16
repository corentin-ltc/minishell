/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:04:13 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 18:58:23 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstlast_offset(t_list *lst, size_t offset)
{
	size_t	size;
	size_t	i;

	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	if (size <= offset)
		return (lst);
	i = 1;
	while (i < size - offset)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

size_t	ft_lstindex(t_list *to_find, t_list *lst)
{
	t_list	*current;
	size_t	index;

	index = 0;
	current = lst;
	while (current)
	{
		if (current == to_find)
			break ;
		current = current->next;
		index++;
	}
	return (index);
}
