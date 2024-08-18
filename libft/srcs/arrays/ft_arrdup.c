/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:09:35 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 16:08:40 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **tab)
{
	char	**new;
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	new = malloc((i + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		if (!new[i])
			return (free_2d((void **)new, i));
		i++;
	}
	new[i] = tab[i];
	return (new);
}
