/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:56:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/30 16:13:29 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		ft_putstr_fd("arr[", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("]: ", 2);
		ft_putendl_fd(arr[i], 2);
		i++;
	}
}
