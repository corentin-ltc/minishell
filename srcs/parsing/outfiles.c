/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:20:30 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 00:54:37 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_outfile(t_data *data, t_cmd *cmd, t_parser *pars, char *name)
{
	char	*trimmed;

	trimmed = ft_strtrim(name, " ");
	if (!trimmed)
		exit_error("malloc", data);
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
	if (pars->append)
		cmd->out_fd = open(trimmed, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		cmd->out_fd = open(trimmed, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd->out_fd < 0)
		perror(trimmed);
	free(trimmed);
}

static void	handle_outfile(t_data *data, t_cmd *cmd, t_parser *pars, size_t *i)
{
	char	*new_line;
	char	*name;
	size_t	start;

	start = *i;
	while (ft_isspace(cmd->line[*i]))
		parse_str(pars, cmd->line, i);
	if (!cmd->line[*i])
		exit_error("syntax error near unexpected token '<'", data);
	while (!ft_istoken(cmd->line[*i]))
		parse_str(pars, cmd->line, i);
	name = ft_substr(cmd->line, start, *i - start);
	if (!name)
		exit_error("malloc", data);
	update_outfile(data, cmd, pars, name);
	free(name);
	new_line = ft_strcut(cmd->line, start - 1, *i);
	if (!new_line)
		exit_error("malloc", data);
	free(cmd->line);
	cmd->line = new_line;
}

static void	get_outfile(t_data *data, t_cmd *cmd)
{
	t_parser	parser;
	size_t		start;
	size_t		i;

	parser = new_parser();
	i = 0;
	while (parse_str(&parser, cmd->line, &i))
	{
		if (parser.outfile)
		{
			handle_outfile(data, cmd, &parser, &i);
			parser.outfile = false;
			i = 0;
		}
	}
}

void	get_outfiles(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		get_outfile(data, data->cmds[i]);
		i++;
	}
}
