/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:56:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/13 17:47:29 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dst, char const *src)
{
	size_t	start;
	size_t	i;

	start = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = 0;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
