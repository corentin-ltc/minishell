/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:34:53 by cle-tort          #+#    #+#             */
/*   Updated: 2024/08/21 03:39:21 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

void	ft_exec(t_data *data, t_cmd **cmds, int index);

char	**get_paths(char **envp);

void	maxi_piping(t_data *data, t_cmd **cmds);

#endif