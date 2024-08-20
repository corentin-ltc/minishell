/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:20:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 23:30:34 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, size_t start, size_t end)
{
	char	*new;
	size_t	i;
	size_t	i_new;

	new = ft_calloc(ft_strlen(str) - (end - start) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	i_new = 0;
	while (str[i])
	{
		if (i < start || i > end)
		{
			new[i_new] = str[i];
			i_new++;
		}
		i++;
	}
	return (new);
}
