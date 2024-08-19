/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:11:32 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 17:25:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*init_cmd(char *line)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->line = line;
	cmd->in_fd = -42;
	cmd->out_fd = -42;
	cmd->is_heredoc = false;
	cmd->args = NULL;
	return (cmd);
}

void	get_cmds(t_data *data)
{
	char	**cmds;
	size_t	i;

	cmds = ft_split_noquotes(data->line, "|");
	if (!cmds)
		exit_error("An allocation failed", data);
	data->cmds = ft_calloc(ft_countwords_noquotes(data->line, "|") + 1,
			sizeof(t_cmd *));
	if (!data->cmds)
	{
		free(cmds);
		exit_error("An allocation failed", data);
	}
	i = 0;
	while (cmds[i])
	{
		data->cmds[i] = init_cmd(cmds[i]);
		if (!data->cmds[i])
		{
			free_2d((void **)&cmds[i], 0);
			exit_error("Cmd allocation failed", data);
		}
		i++;
	}
	free(cmds);
}
