/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:49:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 23:52:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_infile(t_data *data, t_cmd *cmd, char *name)
{
	char	*trimmed;

	trimmed = ft_strtrim(name, " ");
	if (!trimmed)
		exit_error("malloc", data);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	cmd->in_fd = open(trimmed, O_RDONLY, 0777);
	if (cmd->in_fd < 0)
		perror(trimmed);
	free(trimmed);
}

static void	handle_infile(t_data *data, t_cmd *cmd, t_parser *parser, size_t *i)
{
	char	*new_line;
	char	*name;
	size_t	start;

	start = *i;
	while (ft_isspace(cmd->line[*i]))
		parse_str(parser, cmd->line, i);
	if (!cmd->line[*i])
		exit_error("syntax error near unexpected token '<'", data);
	while (!ft_istoken(cmd->line[*i]))
		parse_str(parser, cmd->line, i);
	name = ft_substr(cmd->line, start, *i - start);
	if (!name)
		exit_error("malloc", data);
	update_infile(data, cmd, name);
	free(name);
	new_line = ft_strcut(cmd->line, start - 1, *i);
	if (!new_line)
		exit_error("malloc", data);
	free(cmd->line);
	cmd->line = new_line;
}

static void	get_infile(t_data *data, t_cmd *cmd)
{
	t_parser	parser;
	size_t		i;

	parser = new_parser();
	i = 0;
	while (parse_str(&parser, cmd->line, &i))
	{
		if (parser.infile)
		{
			handle_infile(data, cmd, &parser, &i);
			parser.infile = false;
			i = 0;
		}
	}
}

void	get_infiles(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		printf("Before infile : %s\n", data->cmds[i]->line);
		get_infile(data, data->cmds[i]);
		printf("After infile : %s\n", data->cmds[i]->line);
		printf("Line from the infile : %s\n", get_next_line(data->cmds[i]->in_fd));
		i++;
	}
}
