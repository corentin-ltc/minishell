/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:59:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 01:01:01 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_data(t_data data)
{
	size_t	i;

	printf("Data->line : %s\n", data.line);
	i = 0;
	while (data.cmds[i])
	{
		printf("-----------\n");
		printf("Cmd[%zu]->line: %s\n", i, data.cmds[i]->line);
		printf("infile : %d, outfile : %d\n", data.cmds[i]->in_fd, data.cmds[i]->out_fd);
		printf("-----------\n");
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

void	reset_data(t_data *data)
{
	free(data->line);
	data->line = NULL;
	free_cmds(data->cmds);
	data->cmds = NULL;
}
