/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:47:42 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 23:03:58 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_infile(t_data *data, t_cmd *cmd, size_t index)
{
	// first cmd : dup infile soit STDIN soit in_fd
	if (index == 0 && cmd->in_fd)
		dup2(data->cmds[0]->in_fd, STDIN_FILENO);
	// autre cmd : dup infile soit PIPE soit in_fd
	else if (index != 0)
	{
	}
	if (data->cmds[0]->in_fd > 0)
		close(data->cmds[0]->in_fd);
}

static void	dup_outfile(t_data *data, t_cmd *cmd, size_t index)
{
	// last cmd : dup outfile soit STDOUT soit out_fd
	if (data->cmds[index + 1] == NULL && cmd->out_fd)
		dup2(cmd->out_fd, STDOUT_FILENO);
	// autres : dup outfile soit PIPE soit out_fd
	else if (data->cmds[index + 1])
	{
	}
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
}
void dup_childs(t_data *data, t_cmd *cmd, size_t index)
{
	dup_infile(data, cmd, index);
	dup_outfile(data, cmd, index);
}