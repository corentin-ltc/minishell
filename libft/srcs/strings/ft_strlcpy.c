/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:32:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/05/26 15:40:08 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	dest_len = 0;
	while (src[dest_len] && dest_len < siz - 1)
	{
		dst[dest_len] = src[dest_len];
		dest_len++;
	}
	dst[dest_len] = 0;
	return (src_len);
}
