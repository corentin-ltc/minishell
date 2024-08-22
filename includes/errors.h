/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:48:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 20:25:55 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*functions*/
void	shell_error(char *cmd, char *message);

void	exit_error(char *str, t_data *data);

void	free_data(t_data *data);

void	free_cmds(t_cmd **cmd);

void	reset_data(t_data *data);
void	exit_free(t_data *data);

#endif