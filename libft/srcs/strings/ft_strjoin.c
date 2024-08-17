/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:56:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 19:04:24 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(char const *s1, char const *s2, char const *sep)
{
	size_t	total_len;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep);
	str = malloc((total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	ft_strcat(str, s1);
	ft_strcat(str, sep);
	ft_strcat(str, s2);
	return (str);
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
