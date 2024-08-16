/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:34:09 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/13 17:43:35 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int nb, int fd)
{
	static size_t	count = 0;

	if (nb == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
		count++;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	count++;
	return (count);
}
