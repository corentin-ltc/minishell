/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:02:36 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 22:45:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arradd(char ***tab, char *str)
{
	char	**new_tab;
	size_t	i;

	i = 0;
	while (tab[0][i++]);
	new_tab = malloc((i - 1 + 1 + 1) * sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab[0][i])
	{
		new_tab[i] = tab[0][i];
		i++;
	}
	new_tab[i] = str;
	new_tab[i + 1] = NULL;
	free(*tab);
	*tab = new_tab;
	return (*tab);
}