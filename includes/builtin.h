/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:02:09 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 19:04:33 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/*functions*/
bool	check_builtin(char **argv, char **env);

void	ft_echo(char **argv, char **env);

void	ft_pwd(char **argv, char **env);

void	ft_env(char **argv, char **env);

#endif