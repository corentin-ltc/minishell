/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:42:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:28:30 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*exec*/
void	exec_cmds(t_data *data);
/*dups*/
void	dup_childs(t_data *data, t_cmd *cmd, size_t index);
/*utils*/
void	wait_childs(t_data *data);
void	show_cmd(t_cmd *cmd);

#endif