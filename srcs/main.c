/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 00:25:08 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	single_builtin(t_data *data)
{
	int	stdin;

	if (data->cmds[0] == NULL || data->cmds[1] != NULL)
		return (false);
	if (!is_builtin(data->cmds[0]->args[0]))
		return (false);
	if (ft_strcmp(data->cmds[0]->args[0], "exit"))
	{
		stdin = dup(STDIN_FILENO);
		dup_childs(data, data->cmds[0], 0);
	}
	exec_builtin(data, data->cmds[0]);
	dup2(stdin, STDIN_FILENO);
	close(stdin);
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
			exit_error("success", &data);
		add_history(data.line);
		get_vars(&data);
		get_cmds(&data);
		get_infiles(&data);
		get_outfiles(&data);	
		get_args(&data);
		show_data(data);
		if (!single_builtin(&data))
			exec_cmds(&data);
		printf("exit code : %d\n", data.exit_code);
		reset_data(&data);
	}
	return (0);
}
