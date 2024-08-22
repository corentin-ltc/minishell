/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:47:42 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 23:37:11 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_infile(t_data *data, t_cmd *cmd, size_t index)
{
	//close(data->pipe[1]);
	if (index == 0 && cmd->in_fd)
		dup2(data->cmds[0]->in_fd, STDIN_FILENO);
	else if (index != 0)
		dup2(cmd->in_fd, STDIN_FILENO);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	close(data->pipe[0]);	
}

static void	dup_outfile(t_data *data, t_cmd *cmd, size_t index)
{
	close(data->pipe[0]);
	if (data->cmds[index + 1] == NULL && cmd->out_fd)
	{
		dup2(cmd->out_fd, STDOUT_FILENO);
		
	}
	else if (data->cmds[index + 1])
	{
		if 	(dup2(cmd->out_fd, STDOUT_FILENO) < 0)
		{
			perror("Dup2");
		}
	}
	close(data->pipe[1]);
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
}
void dup_childs(t_data *data, t_cmd *cmd, size_t index)
{
	dup_infile(data, cmd, index);
	dup_outfile(data, cmd, index);
}