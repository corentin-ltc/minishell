/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isabovemid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:56:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 17:01:53 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isabovemid(t_list *to_find, t_list *lst)
{
	if (ft_lstindex(to_find, lst) + 1 > ft_lstsize(lst) / 2)
		return (1);
	return (0);
}
