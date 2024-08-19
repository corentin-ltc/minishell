/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 01:49:17 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_temp_args(t_data *data)
{
	t_cmd	*cmd;
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		cmd = data->cmds[i];
		cmd->args = ft_split_noquotes(cmd->line, " ");
		if (!cmd->args)
			exit_error("An allocation failed", data);
		i++;
	}
}

void	minishell_loop(t_data *data)
{
	size_t	i;

	while (true)
	{
		data->line = readline("miniprout > ");
		if (!data->line)
			exit_error("success", data);
		add_history(data->line);
		get_vars(data);
		get_cmds(data);
		get_infiles(data);
		get_outfiles(data);
		show_data(*data);
		reset_data(data);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	set_signals();
	init_data(&data, env);
	minishell_loop(&data);
	return (0);
}
