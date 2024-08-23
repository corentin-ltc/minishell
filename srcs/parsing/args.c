/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:08:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 07:37:44 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *str)
{
	char	*new;
	size_t	quotes;

	quotes = count_quotes(str);
	printf("quotes count : %zu\n", quotes);
	new = NULL;
	return (new);
}

static void	get_arg(t_data *data, t_cmd *cmd)
{
	char	*str_noquotes;
	size_t	i;

	cmd->args = ft_split_words(cmd->line, " ");
	if (!cmd->args)
		exit_error("malloc", data);
	i = 0;
	while (cmd->args[i])
	{
		printf("Trimming : %s\n", cmd->args[i]);
		str_noquotes = remove_quotes(cmd->args[i]);
		if (!str_noquotes)
			exit_error("trim malloc", data);
		free(cmd->args[i]);
		cmd->args[i] = str_noquotes;
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
