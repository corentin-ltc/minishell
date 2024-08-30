/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:02:36 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/30 17:16:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arradd(char ***tab, char *str)
{
	char	**new_tab;
	size_t	i;

	i = 0;
	while ((*tab)[i])
		i++;
	new_tab = ft_calloc(i + 1 + 1, sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	while ((*tab)[i])
	{
		new_tab[i] = (*tab)[i];
		i++;
	}
	new_tab[i] = str;
	free(*tab);
	*tab = new_tab;
	return (*tab);
}
