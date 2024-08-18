/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:23:39 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:28:15 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// while (str[i])
// {
// 	if (str[i] == '"')
// 	{
// 		if (parser.d_quotes == true)
// 			parser.d_quotes = false;
// 		else if (parser.quotes == false)
// 			(parser.d_quotes = true)
// 	}
// 	else if (str[i] == d_quotes =)
// }







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
		if (is_valid && line[i] == '$' && ft_isalnum(line[i + 1]))
			return (i);
		i++;
	}
	return (-42);
}
