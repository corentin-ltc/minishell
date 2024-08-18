/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:10:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/05/18 19:02:51 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	ptr = (char *) dest;
	i = 0;
	while (i < n)
	{
		if (dest < src)
			ptr[i] = *((char *)src + i);
		else
			ptr[n - i - 1] = *((char *)src + n - i - 1);
		i++;
	}
	return (dest);
}
