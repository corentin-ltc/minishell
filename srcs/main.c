/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/25 18:26:33 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	single_builtin(t_data *data)
{
	int	stdout;

	if (data->cmds[0] == NULL || data->cmds[1] != NULL)
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

static bool	no_empty_cmd(t_data data)
{
	size_t	i;

	i = 0;
	while (data.cmds[i])
	{
		if (data.cmds[i]->args[0] == NULL)
		{
			shell_error("pipe", "empty command");
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	is_valid_line(char *line)
{
	//check si quote ouverte
	if (count_quotes(line) % 2 != 0)
	{
		ft_putstr_fd("open quotes found\n", 2);
		return (false);
	}
	//check si pipe vide
	if (empty_pipes(line))
	{
		ft_putstr_fd("empty pipes found\n", 2);
		return (false);
	}
	//check si triple chevron
	return (true);
}


int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_data(&data, env);
	while (true)
	{
		data.line = readline("minishell > ");
		if (!data.line)
			exit_free(&data);
		add_history(data.line);
		if (is_valid_line(data.line))
		{
			get_vars(&data);
			get_cmds(&data);
			get_infiles(&data);
			get_outfiles(&data);	
			get_args(&data);
			show_data(data);
			if (!single_builtin(&data))
				exec_cmds(&data);
		}
		// printf("exit code : %d\n", data.exit_code);
		reset_data(&data);
	}
	return (0);
}
