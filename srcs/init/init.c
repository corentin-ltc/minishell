/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:59:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:48:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		get_cmds(data);
		i = 0;
		while (data->cmds[i])
		{
			get_vars(data, data->cmds[i]);
			ft_putendl(data->cmds[i]->line);
			i++;
		}
		free(data->line);
		free_cmds(data->cmds);
	}
}
