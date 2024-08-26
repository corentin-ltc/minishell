/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:25:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 18:58:19 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_cmd(t_cmd *cmd)
{
	ft_putstr_fd("\n---------\nExecuting : ", 2);
	ft_putendl_fd(cmd->line, 2);
	ft_putstr_fd("clean_line :", 2);
	ft_putendl_fd(cmd->clean_line, 2);
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
		waitpid(-1, &data->exit_code, 0);
		if (WIFEXITED(data->exit_code))
			data->exit_code = WEXITSTATUS(data->exit_code);
		data->childs--;
	}
}