/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 15:46:55 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_loop(t_data *data)
{
	size_t	i;

	while (true)
	{
		data->line = readline("minishell > ");
		if (!data->line)
			exit_error("success", data);
		add_history(data->line);
		get_vars(data);
		get_cmds(data);
		get_infiles(data);
		get_outfiles(data);
		get_args(data);
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
