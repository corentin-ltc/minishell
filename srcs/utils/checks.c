/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:47:50 by nabil             #+#    #+#             */
/*   Updated: 2024/08/26 01:16:50 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	single_builtin(t_data *data)
{
	int	stdout;

	if (data->cmds[0] == NULL || data->cmds[1] || !data->cmds[0]->is_valid)
		return (false);
	if (!is_builtin(data->cmds[0]->args[0]))
		return (false);
	if (!data->cmds[0]->is_valid)
	{
		data->exit_code = 1;
		return (false);
	}
	if (ft_strcmp(data->cmds[0]->args[0], "exit"))
	{
		stdout = dup(STDOUT_FILENO);
		if (data->cmds[0]->out_fd)
			dup2(data->cmds[0]->out_fd, STDOUT_FILENO);
	}
	exec_builtin(data, data->cmds[0]);
	dup2(stdout, STDOUT_FILENO);
	close(stdout);
	return (true);
}

size_t	count_quotes(char *str)
{
	t_parser	parser;
	size_t		count;
	size_t		i;

	parser = new_parser();
	count = 0;
	i = 0;
	while (update_parser(&parser, str[i]))
	{
		if (!parser.quotes && (str[i] == '\'' || str[i] == '"'))
			count++;
		else if (parser.d_quotes && str[i] == '"')
			count++;
		else if (parser.s_quotes && str[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

static bool	empty_pipes(char *str)
{
	t_parser	parser;
	size_t		i;

	parser = new_parser();
	i = 0;
	while (update_parser(&parser, str[i]))
	{
		while (str[i] && (parser.quotes || str[i] != '|'))
			parse_str(&parser, str, &i);
		if (str[i] == '\0')
			break ;
		if (str[i] == '|')
			i++;
		while (isspace(str[i]))
			parse_str(&parser, str, &i);
		if (str[i] == '|')
			return (true);
		i++;
	}
	return (false);
}
static bool	triple_redirection(char *str)
{
	t_parser	parser;
	size_t		i;

	parser = new_parser();
	i = 0;
	while (update_parser(&parser, str[i]))
	{
		while (str[i] && (parser.quotes || (str[i] != '<' && str[i] != '>')))
			parse_str(&parser, str, &i);
		if (str[i] == '\0')
			break ;
		if (str[i] == str[i + 1])
			i += 2;
		else
			i += 1;
		while (isspace(str[i]))
			parse_str(&parser, str, &i);
		if (ft_isfile_limiter(str[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_valid_line(char *line)
{
	if (count_quotes(line) % 2 != 0)
	{
		ft_putstr_fd("open quotes found\n", 2);
		return (false);
	}
	if (empty_pipes(line))
	{
		ft_putstr_fd("empty pipes found\n", 2);
		return (false);
	}
	if (triple_redirection(line))
	{
		ft_putstr_fd("syntax error\n", 2);
		return (false);
	}
	return (true);
}