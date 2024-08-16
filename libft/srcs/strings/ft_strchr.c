/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:31:52 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/29 20:48:41 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char) c;
	us = (unsigned char *) s;
	i = 0;
	while (us[i])
	{
		if (us[i] == uc)
			return ((char *) &us[i]);
		i++;
	}
	if (us[i] == uc)
		return ((char *) &us[i]);
	return (NULL);
}
