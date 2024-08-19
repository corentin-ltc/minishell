/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:49:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 01:49:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_here_doc(t_cmd *cmd, char *limiter)
{
	char	*line;

	cmd->in_fd = open("here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (cmd->in_fd < 1)
		return (perror("here_doc"));
	ft_putstr("heredoc> ");
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, cmd->in_fd);
		free(line);
		ft_putstr("heredoc> ");
		line = get_next_line(STDIN_FILENO);
	}
	close(cmd->in_fd);
	cmd->in_fd = open("here_doc", O_RDONLY, 0777);
	if (cmd->in_fd < 1)
		perror("here_doc");
}

static void	update_infile(t_data *data, t_cmd *cmd, t_parser *pars, char *name)
{
	char	*trimmed;

	trimmed = ft_strtrim(name, " ");
	if (!trimmed)
		exit_error("malloc", data);
	printf("name : %s\n", trimmed);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	if (pars->here_doc == false)
		cmd->in_fd = open(trimmed, O_RDONLY, 0777);
	else
		get_here_doc(cmd, name);
	if (cmd->in_fd < 0)
		perror(trimmed);
	free(trimmed);
}

static void	handle_infile(t_data *data, t_cmd *cmd, t_parser *pars, size_t *i)
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
	update_infile(data, cmd, pars, name);
	free(name);
	start--;
	if (pars->here_doc)
		start--;
	new_line = ft_strcut(cmd->line, start, *i);
	if (!new_line)
		exit_error("malloc", data);
	printf("new_line : %s\n", new_line);
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
		get_infile(data, data->cmds[i]);
		i++;
	}
}
