/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:49:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 22:22:38 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

int	here_doc_loop(t_data *data, t_cmd *cmd, char *limiter)
{
	char	*line;
	char	*line_tmp;

	line_tmp = readline("heredoc> ");
	if (!line_tmp)
		return (0);
	line = ft_strjoin(line_tmp, "\n");
	if (!line)
	{
		free(line_tmp);
		exit_error("Allocation failed", data);
	}
	free(line_tmp);
	if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
		g_signal = -42;
	else
		ft_putstr_fd(line, cmd->in_fd);
	free(line);
	return (1);
}

static void	get_here_doc(t_data *data, t_cmd *cmd, char *limiter)
{
	cmd->in_fd = open(HERE_DOC, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd->in_fd < 1)
		return (perror("here_doc"));
	while (g_signal != -42)
	{
		if (!here_doc_loop(data, cmd, limiter))
			break;
	}
	close(cmd->in_fd);
	cmd->in_fd = open(HERE_DOC, O_RDONLY, 0777);
	if (cmd->in_fd < 1)
		perror("here_doc");
}

static void	update_infile(t_data *data, t_cmd *cmd, t_parser *pars, char *name)
{
	char	*trimmed;

	trimmed = ft_strtrim(name, " ");
	if (!trimmed)
		exit_error("malloc", data);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	if (pars->here_doc == false)
		cmd->in_fd = open(trimmed, O_RDONLY, 0777);
	else
	{
		signal(SIGINT, sig_newline_heredoc);
		get_here_doc(data, cmd, name);
		signal(SIGINT, sig_newline);
	}
	if (cmd->is_valid && cmd->in_fd < 0)
	{
		perror(trimmed);
		cmd->is_valid = false;
	}
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
	while (pars->quotes || !ft_isfile_limiter(cmd->line[*i]))
		parse_str(pars, cmd->line, i);
	name = get_filename(cmd->line + start, *pars);
	if (!name)
		exit_error("malloc", data);
	update_infile(data, cmd, pars, name);
	free(name);
	start--;
	if (pars->here_doc)
		start--;
	new_line = ft_strcut(cmd->line, start, *i - 1);
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
		get_infile(data, data->cmds[i]);
		// ft_putstr_fd("This is the infile\n", data->cmds[i]->in_fd);
		i++;
	}
}
