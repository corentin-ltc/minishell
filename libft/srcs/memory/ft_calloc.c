/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:06 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 19:04:15 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	area;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	area = nmemb * size;
	tab = malloc(area);
	if (!tab)
		return (NULL);
	ft_bzero(tab, area);
	return (tab);
}
