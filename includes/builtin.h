/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:02:09 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 18:52:22 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/*functions*/
bool	check_builtin(char **argv);

void	ft_echo(char **argv);

void	ft_pwd(char **argv);

#endif