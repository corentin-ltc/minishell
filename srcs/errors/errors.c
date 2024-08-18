/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:46:40 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 16:16:35 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_error(char *cmd, char *message)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(message, 2);
}

void	exit_error(char *str, t_data *data)
{
	ft_putendl_fd(str, 2);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

void	free_cmds(t_cmd **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i]->line)
			free(cmd[i]->line);
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	free_data(t_data *data)
{
	if (data->env)
		free_2d((void **)data->env, 0);
	if (data->line)
		free(data->line);
	if (data->cmds)
		free_cmds(data->cmds);
}
