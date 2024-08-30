/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:02:36 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/30 17:26:47 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_index(char ***tab, size_t index)
{
	char	**new_tab;
	size_t	i;
	size_t	j;

	i = 0;
	while ((*tab)[i])
		i++;
	new_tab = ft_calloc((i - 1) + 1, sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	j = 0;
	while ((*tab)[i])
	{
		if (i != index)
		{
			new_tab[j++] = (*tab)[i];
		}
		i++;
	}
	free((*tab)[index]);
	free(*tab);
	*tab = new_tab;
	return (*tab);
}
