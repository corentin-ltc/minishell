/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:47:42 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 07:08:33 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_lastcmd(t_data *data, size_t index)
{
	return (data->cmds[index + 1] == NULL);
}

static void	dup_infile(t_data *data, t_cmd *cmd, size_t index)
{
	close(data->pipe[0]);
	if (index == 0 && cmd->in_fd == 0)
		cmd->in_fd = dup(STDIN_FILENO);
	dup2(cmd->in_fd, STDIN_FILENO);
	close(cmd->in_fd);
}

static void	dup_outfile(t_data *data, t_cmd *cmd, size_t index)
{
	if (is_lastcmd(data, index) && cmd->out_fd == 0)
		cmd->out_fd = dup(STDOUT_FILENO);
	else if (!is_lastcmd(data, index) && cmd->out_fd == 0)
		cmd->out_fd = dup(data->pipe[1]);
	close(data->pipe[1]);
	dup2(cmd->out_fd, STDOUT_FILENO);
	close(cmd->out_fd);
}
void dup_childs(t_data *data, t_cmd *cmd, size_t index)
{
	dup_infile(data, cmd, index);
	dup_outfile(data, cmd, index);
}