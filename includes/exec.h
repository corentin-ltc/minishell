/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:42:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 01:34:22 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*exec*/
void	exec_cmds(t_data *data);
/*utils*/
void	wait_childs(t_data *data);
void	show_cmd(t_cmd *cmd);

#endif