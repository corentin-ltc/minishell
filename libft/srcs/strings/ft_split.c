/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:12:14 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 23:08:20 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_strchr(set, s[i]))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char *set)
{
	char	**tab;
	size_t	col;
	size_t	start;
	size_t	i;

	tab = malloc((ft_countwords(s, set) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	col = 0;
	i = 0;
	while (s[i])
	{
		i += ft_skipcharset(&s[i], set);
		start = i;
		i += ft_reachcharset(&s[i], set);
		if (start == i)
			break ;
		tab[col] = ft_substr(s, start, i - start);
		if (!tab[col])
			return (free_2d((void **)tab, 0));
		col++;
	}
	tab[col] = 0;
	return (tab);
}
