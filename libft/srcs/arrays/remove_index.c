/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:02:36 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 21:33:50 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_index(char ***tab, size_t index)
{
	char	**new_tab;
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[0][i++]);
	new_tab = malloc((i - 1) * sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	j = 0;
	while (tab[0][i])
	{
		if (i != index)
		{
			new_tab[j] = tab[0][i];
			j++;
		}
		i++;
	}
	new_tab[j] = NULL;
	*tab = new_tab;
	return (*tab);
}

// int	main(int argc, char **argv, char **ev)
// {
// 	char **env;
	
// 	env = ft_arrdup(ev);
// 	ft_putarr(env);
// 	ft_remove_index(&env, 55);
// 	get_next_line(0);
// 	ft_putarr(env);
// 	free_2d((void **)env, 0);
// 	argc++;
// 	argv++;
// }