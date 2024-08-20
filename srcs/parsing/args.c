/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:08:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 16:35:29 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_arg(t_data *data, t_cmd *cmd)
{
	cmd->args = ft_split_words(cmd->line, " ");
	if (!cmd->args)
		exit_error("malloc", data);
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
