/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:16:53 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/01 17:54:45 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_a_valid_base(const char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

size_t	ft_nbrlen_base(long nbr, const char *base)
{
	size_t	count;
	long	base_len;

	base_len = (long)ft_strlen(base);
	count = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr >= base_len)
	{
		count++;
		nbr /= base_len;
	}
	return (count);
}

size_t	ft_unsignedlen_base(unsigned long nbr, const char *base)
{
	size_t			count;
	unsigned long	base_len;

	base_len = (unsigned long)ft_strlen(base);
	count = 1;
	while (nbr >= base_len)
	{
		count++;
		nbr /= base_len;
	}
	return (count);
}

size_t	ft_putnbr_base(long nbr, const char *base)
{
	long	base_len;

	if (!is_a_valid_base(base))
		return (0);
	base_len = (long)ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base(nbr * -1, base);
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	if (nbr >= 0)
		ft_putchar_fd(base[nbr % (base_len)], 1);
	return (ft_nbrlen_base(nbr, base));
}

size_t	ft_putunsigned_base(unsigned long int nbr, const char *base)
{
	size_t			base_len;

	if (!is_a_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		ft_putunsigned_base(nbr / base_len, base);
	ft_putchar_fd(base[nbr % (base_len)], 1);
	return (ft_unsignedlen_base(nbr, base));
}
