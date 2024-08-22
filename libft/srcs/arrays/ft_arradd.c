/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:02:36 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:37:19 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arradd(char ***tab, char *str)
{
	char	**old_tab;
	char	**new_tab;
	size_t	i;

	old_tab = *tab;
	i = 0;
	while (old_tab[i])
		i++;
	new_tab = calloc(i + 1 + 1, sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (old_tab[i])
	{
		new_tab[i] = old_tab[i];
		i++;
	}
	new_tab[i] = str;
	free(*tab);
	*tab = new_tab;
	return (*tab);
}
