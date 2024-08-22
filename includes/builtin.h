/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:02:09 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:17:58 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/*functions*/
bool	check_builtin(t_data *data, t_cmd *cmd);

void	ft_echo(t_data *data, t_cmd *cmd);

void	ft_cd(t_data *data, t_cmd *cmd);

void	ft_pwd(t_data *data, t_cmd *cmd);

void	ft_env(t_data *data, t_cmd *cmd);

void	ft_unset(t_data *data, t_cmd *cmd);

void	ft_export(t_data *data, t_cmd *cmd);

void	ft_exit(t_data *data, t_cmd *cmd);

#endif