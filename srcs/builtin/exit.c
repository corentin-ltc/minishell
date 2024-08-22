/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 21:32:40 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *data, t_cmd *cmd)
{
	if (cmd->args[1])
	{
		data->exit_code = ft_atoi(cmd->args[1]);
		if (data->exit_code < 0 || data->exit_code > 255)
			data->exit_code = 255;
	}
	if (data->cmds[1] == NULL)
		ft_putstr("exit\n");
	exit_free(data);
}
