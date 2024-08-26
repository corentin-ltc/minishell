/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 19:21:12 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc > 2 && argv)
		exit_error("Too many arguments", NULL);
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
			get_cleanlines(&data);
			get_args(&data);
			// show_data(data);
			if (!single_builtin(&data))
				exec_cmds(&data);
		}
		reset_data(&data);
	}
	return (0);
}
