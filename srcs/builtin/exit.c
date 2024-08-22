/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:27:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *data, t_cmd *cmd)
{
	int	status;

	status = EXIT_SUCCESS;
	if (cmd->args[1])
	{
		status = ft_atoi(cmd->args[1]);
		if (status < 0 || status > 255)
			status = 255;
	}
	data->exit_code = status;
	if (data->cmds[1] == NULL)
		ft_putstr("exit\n");
	exit_free(data);
}
