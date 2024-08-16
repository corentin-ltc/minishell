/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:54:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 03:46:26 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_splittoi(char *str, char *set)
{
	int		*tab;
	char	**split;
	size_t	i;

	tab = malloc(ft_countwords(str, set) * sizeof(int));
	if (!tab)
		return (NULL);
	split = ft_split(str, set);
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		tab[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (tab);
}
