/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:56:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 02:13:51 by cle-tort         ###   ########.fr       */
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
		ft_putstr_fd(ft_itoa(i), 2);
		ft_putstr_fd("]: ", 2);
		ft_putendl_fd(arr[i], 2);
		//ft_printf("arr[%d]: %s\n", i, arr[i]);
		i++;
	}
}
