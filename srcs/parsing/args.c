/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:08:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 07:54:31 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *str)
{
	char		*new;
	t_parser	parser;
	size_t		i;
	size_t		j;

	new = calloc(ft_strlen(str) - count_quotes(str) + 1, sizeof(char));
	if (!new)
		return (NULL);
	parser = new_parser();
	j = 0;
	i = 0;
	while (str[i])
	{
		update_parser(&parser, str[i]);
		if ((!parser.quotes && str[i] != '\'' && str[i] != '"')
			|| (parser.d_quotes && str[i] != '"')
			|| (parser.s_quotes && str[i] != '\''))
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
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
