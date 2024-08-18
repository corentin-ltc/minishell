/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:23:39 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:43:04 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(char *line)
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

int	get_varindex(char *line)
{
	t_parser	parser;
	size_t		i;

	parser = new_parser();
	i = 0;
	while (line[i])
	{
		update_parser(&parser, line[i]);
		if (!parser.s_quotes && line[i] == '$' && ft_isalnum(line[i + 1]))
			return (i);
		i++;
	}
	return (-42);
}
