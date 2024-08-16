/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:19:29 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 18:54:19 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

/*va_arg / write*/
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

void	ft_putstr(const char *s);

void	ft_putendl(const char *s);

void	ft_putarr(char **arr);

int		ft_putchar_fd(char c, int fd);

int		ft_putstr_fd(const char *s, int fd);

size_t	ft_putendl_fd(const char *s, int fd);

size_t	ft_putnbr_fd(int nbr, int fd);

size_t	ft_putnbr_base(long nbr, const char *base);

size_t	ft_putunsigned_base(unsigned long int nbr, const char *base);

void	ft_putlst(t_list *lst);

#endif