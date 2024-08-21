/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:47:42 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 19:59:43 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_infile(t_data *data, t_cmd *cmd, size_t index)
{
	if (index == 0 && cmd->in_fd)
	{
		// dup infile soit STDIN soit in_fd
		dup2(data->cmds[0]->in_fd, STDIN_FILENO);
		if (data->cmds[0]->in_fd > 0)
			close(data->cmds[0]->in_fd);
	}
	else if (index != 0)
	{
		// dup infile soit pipe soit in_fd
	}
}

static void	dup_outfile(t_data *data, t_cmd *cmd, size_t index)
{
	if (data->cmds[index + 1] == NULL && cmd->out_fd)
	{
		// dup outfile soit STDOUT soit out_fd
		dup2(cmd->out_fd, STDOUT_FILENO);
		if (cmd->out_fd > 0)
			close(cmd->out_fd);
	}
	else if (data->cmds[index])
	{
		// dup infile soit pipe soit in_fd
	}

}
void dup_childs(t_data *data, t_cmd *cmd, size_t index)
{
	dup_infile(data, cmd, index);
	dup_outfile(data, cmd, index);
}