/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:23:39 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 17:18:28 by nbellila         ###   ########.fr       */
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

char	*get_varname(char *line)
{
	size_t	i;
	bool	is_valid;

	is_valid = true;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			is_valid = false;
			i++;
			while (line[i] && line[i] != '\'')
				i++;
			if (line[i] == '\'')
				is_valid = true;
		}
		if (is_valid && line[i] == '$')
		{
			while (ft_isalnum(line[i]))
				i++;
		}
		i++;
	}
	return (NULL);
}
