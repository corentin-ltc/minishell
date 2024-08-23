/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 07:08:34 by nabil            ###   ########.fr       */
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
		get_vars(&data);
		get_cmds(&data);
		get_infiles(&data);
		get_outfiles(&data);	
		get_args(&data);
		// show_data(data);
		if (!single_builtin(&data))
			exec_cmds(&data);
		// printf("exit code : %d\n", data.exit_code);
		reset_data(&data);
	}
	return (0);
}
