/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:25:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 22:06:55 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_cmd(t_cmd *cmd)
{
	ft_putstr_fd("\n---------\nExecuting : ", 2);
	ft_putendl_fd(cmd->line, 2);
	ft_putstr_fd("in : ", 2);
	ft_putstr_fd(ft_itoa(cmd->in_fd), 2);
	ft_putstr_fd(", out : ", 2);
	ft_putendl_fd(ft_itoa(cmd->out_fd), 2);
	ft_putstr_fd("---------\n\n", 2);
}

void	wait_childs(t_data *data)
{
	while (data->childs)
	{
		waitpid(0, &data->exit_code, 0);
		data->childs--;
	}
}