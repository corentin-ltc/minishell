/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:59 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:11:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char const *src)
{
	size_t	start;
	size_t	i;

	start = ft_strlen(dst);
	i = 0;
	while (src && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = 0;
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (siz < dst_len)
		return (src_len + siz);
	i = 0;
	while (src[i] && dst_len + i + 1 < siz)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (src_len + dst_len);
}
