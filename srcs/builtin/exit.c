/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 07:11:59 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *data, t_cmd *cmd)
{
	size_t	i;

	data->exit_code = 0;
	if (cmd->args[1])
	{
		data->exit_code = 1;
		if (cmd->args[2])
			return (shell_error("exit", "too many arguments"));
		i = 0;
		while (cmd->args[1][i])
		{
			if (!ft_isdigit(cmd->args[1][i]) && (cmd->args[1][i] != '+'
			|| cmd->args[1][i] != '-'))
				return (shell_error("exit", "numeric argument required"));
			i++;
		}
		data->exit_code = ft_atoi(cmd->args[1]);
		if (data->exit_code < 0 || data->exit_code > 255)
			data->exit_code = 255;
	}
	if (data->cmds[1] == NULL)
		ft_putstr("exit\n");
	exit_free(data);
}
