/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:39:35 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 19:56:17 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_cmd(t_cmd *cmd)
{
	ft_putstr_fd("\n---------\nExecuting : ", 2);
	ft_putendl_fd(cmd->line, 2);
	ft_putstr_fd("in : ", 2);
	ft_putstr_fd(ft_itoa(cmd->in_fd), 2);
	ft_putstr_fd(", out : ", 2);
	ft_putendl_fd(ft_itoa(cmd->in_fd), 2);
	ft_putstr_fd("---------\n\n", 2);
}

static void	handle_child(t_data *data, t_cmd *cmd, size_t index)
{
	// printf("Child process\n");
	dup_childs(data, cmd, index);
	execve(cmd->args[0], cmd->args, data->env);
	exit_error("", data);
}

static void	handle_parent(t_data *data, t_cmd *cmd)
{
	// printf("Parent process\n");
}

static void	ft_exec(t_data *data, t_cmd *cmd, size_t index)
{
	pid_t	pid;

	show_cmd(cmd);
	pid = fork();
	data->childs++;
	if (pid == 0)
		handle_child(data, cmd, index);
	else
		handle_parent(data, cmd);
}

void	exec_cmds(t_data *data)
{
	t_cmd	*cmd;
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		cmd = data->cmds[i];
		ft_exec(data, cmd, i);
		i++;
	}
	wait_childs(data);
}
