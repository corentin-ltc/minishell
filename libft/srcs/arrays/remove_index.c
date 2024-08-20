/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:02:36 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 15:46:50 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_index(char ***tab, size_t index)
{
	char	**new_tab;
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[0][i])
		i++;
	new_tab = malloc((i - 2 + 1) * sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	j = 0;
	while (tab[0][i])
	{
		if (i != index)
		{
			new_tab[j++] = tab[0][i];
		}
		i++;
	}
	new_tab[j] = NULL;
	free(tab[0][index]);
	free(*tab);
	*tab = new_tab;
	return (*tab);
}
