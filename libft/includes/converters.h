/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:16:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/21 18:16:17 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTERS_H
# define CONVERTERS_H

# include "linked_lists.h"

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_abs(int nb);

int		ft_lsttoi(t_list *lst);

char	*ft_lsttos(t_list *lst);

char	*ft_itoa(int n);

int		ft_atoi(const char *nptr);

#endif