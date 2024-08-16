/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 03:24:34 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 20:15:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_2d(void **tab, size_t size)
{
	size_t	i;

	if (!tab)
		return (NULL);
	i = 0;
	if (size)
	{
		while (tab && i < size)
		{
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (tab[i])
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
