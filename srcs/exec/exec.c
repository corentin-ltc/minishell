/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:39:35 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 19:18:08 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_cmd(t_cmd *cmd)
{
	printf("---------\n");
	printf("Executing : %s\n", cmd->line);
	printf("in : %d, out : %d\n", cmd->in_fd, cmd->out_fd);
	ft_putarr(cmd->args);
	printf("---------\n");
}

static void	handle_child(t_data *data, t_cmd *cmd)
{
	printf("Child process\n");
	//todo: dup current out_fd
	execve(cmd->args[0], cmd->args, data->env);
}

static void	handle_parent(t_data *data, t_cmd *cmd)
{
	printf("Parent process\n");
	//todo: dup next in_fd
}

static void	ft_exec(t_data *data, t_cmd *cmd)
{
	pid_t	pid;

	show_cmd(cmd);
	pid = fork();
	data->childs++;
	if (pid == 0)
		handle_child(data, cmd);
	else
		handle_parent(data, cmd);
}

void	exec_cmds(t_data *data)
{
	t_cmd	*cmd;
	size_t	i;

	//todo: dup first in_fd
	i = 0;
	while (data->cmds[i] && data->cmds[i + 1])
	{
		printf("---boucle\n");
		cmd = data->cmds[i];
		ft_exec(data, cmd);
		i++;
	}
	//todo: dup last out_fd
	ft_exec(data, data->cmds[i]);
	while (data->childs)
	{
		waitpid(0, &data->exit_code, 0);
		data->childs--;
	}
}