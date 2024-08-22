/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:08:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 00:16:40 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_arg(t_data *data, t_cmd *cmd)
{
	char	*trimmed;
	size_t	i;

	cmd->args = ft_split_words(cmd->line, " ");
	if (!cmd->args)
		exit_error("malloc", data);
	i = 0;
	while (cmd->args[i])
	{
		if (cmd->args[i][0] == '"')
			trimmed = ft_strtrim(cmd->args[i], "\"");
		else
			trimmed = ft_strtrim(cmd->args[i], "'");
		if (!trimmed)
			exit_error("malloc", data);
		free(cmd->args[i]);
		cmd->args[i] = trimmed;
		i++;
	}
}

void	get_args(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		get_arg(data, data->cmds[i]);
		i++;
	}
}
