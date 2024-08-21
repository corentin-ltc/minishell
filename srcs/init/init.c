/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:59:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 18:37:05 by nbellila         ###   ########.fr       */
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
		printf("-----------Cmd[%zu]-----------\n", i);
		printf("line: %s\n", data.cmds[i]->line);
		printf("infile : %d", data.cmds[i]->in_fd);
		printf(", outfile : %d\n", data.cmds[i]->out_fd);
		if (data.cmds[i]->args)
			ft_putarr(data.cmds[i]->args);
		printf("----------------------------\n");
		i++;
	}
}

static char	**get_path(t_data *data)
{
	char *path;

	if (data->path)
		free_2((void **)data->path, 2);
	data->path = NULL;
	path = ft_getenv("PATH", data->env);
	if (!path)
		return ;
	data->path = ft_split(path, ":");
	if (!data->path)
		exit_error("Split allocation failed", data);
}

void	init_data(t_data *data, char **env)
{
	set_signals();
	data->env = ft_arrdup(env);
	if (!data->env)
		exit_error("An allocation failed", NULL);
	data->cmds = NULL;
	data->line = NULL;
	data->path = NULL;
	get_path(data);
}

void	reset_data(t_data *data)
{
	free(data->line);
	data->line = NULL;
	free_cmds(data->cmds);
	data->cmds = NULL;
	get_paths(data);
}
