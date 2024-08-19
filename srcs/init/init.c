/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:59:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 17:06:44 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_data(t_data data)
{
	size_t	i;

	printf("Data->line : %s\n", data.line);
	i = 0;
	while (data.cmds[i])
	{
		printf("Cmd[%zu]->line: %s\n", i, data.cmds[i]->line);
		i++;
	}
}

void	init_data(t_data *data, char **env)
{
	data->env = ft_arrdup(env);
	if (!data->env)
		exit_error("An allocation failed", NULL);
	data->cmds = NULL;
	data->line = NULL;
}

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
		show_data(*data);
		reset_data(data);
	}
}
