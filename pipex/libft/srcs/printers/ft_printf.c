/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:08:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/29 19:10:11 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printstr(const char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

static size_t	ft_putptr_hexa(void *ptr)
{
	size_t				count;
	unsigned long int	nbr;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	nbr = (unsigned long int)ptr;
	count = ft_putstr_fd("0x", 1);
	count += ft_putunsigned_base(nbr, HEXA);
	return (count);
}

static int	ft_putformat(const char *str, va_list ap)
{
	if (!*str)
		return (-1);
	if (*str == '%')
		return (ft_putchar_fd('%', 1));
	if (*str == 'c')
		return (ft_putchar_fd((va_arg(ap, int)), 1));
	if (*str == 's')
		return (ft_printstr(va_arg(ap, const char *)));
	if (*str == 'p')
		return (ft_putptr_hexa(va_arg(ap, void *)));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr_base(va_arg(ap, signed int), DECIMAL));
	if (*str == 'u')
		return (ft_putunsigned_base(va_arg(ap, unsigned int), DECIMAL));
	if (*str == 'x')
		return (ft_putunsigned_base(va_arg(ap, unsigned int), HEXA));
	if (*str == 'X')
		return (ft_putunsigned_base(va_arg(ap, unsigned int), HEXA_UP));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed;
	size_t	print_count;
	size_t	i;

	va_start(ap, str);
	if (!str)
		return (-1);
	print_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			printed = ft_putformat(&str[i++ + 1], ap);
		else
			printed = ft_putchar_fd(str[i], 1);
		if (printed < 0)
			return (-1);
		print_count += printed;
		if (str[i])
			i++;
	}
	va_end(ap);
	return (print_count);
}
