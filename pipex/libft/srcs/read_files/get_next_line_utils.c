/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:22:43 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/22 17:58:50 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lststrlen(t_list *lst)
{
	size_t	total_len;
	size_t	i;

	total_len = 0;
	while (lst)
	{
		i = 0;
		while (ft_lsttos(lst)[i] && ft_lsttos(lst)[i] != '\n')
			i++;
		total_len += i;
		if (!lst->next && ft_lsttos(lst)[i] == '\n')
			total_len++;
		lst = lst->next;
	}
	return (total_len);
}

int	ft_lstcontains(t_list *lst, char c)
{
	t_list	*current;

	if (!lst)
		return (0);
	current = lst;
	while (current)
	{
		if (ft_strcontains(current->content, c) >= 0)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_strcontains(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
