/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:39:35 by nbellila          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_exec(t_data *data, t_cmd *cmd, char **path)
{
	size_t	i;
	char	*exec_backslash;
	char	*exec;

	i = 0;
	while (path[i])
	{
		exec_backslash = ft_strjoin(path[i++], "/");
		if (!exec_backslash)
			exit_error("An allocation failed\n", data);
		exec = ft_strjoin(exec_backslash, cmd->args[0]);
		free(exec_backslash);
		if (!exec)
			exit_error("An allocation failed\n", data);
		if (access(exec, X_OK) != -1)
		{
			free(cmd->args[0]);
			cmd->args[0] = exec;
			return ;
		}
		free(exec);
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd->args[0], 2);
	cmd->is_valid = false;
}

static void	handle_child(t_data *data, t_cmd *cmd, size_t index)
{
	// printf("Child process\n");
	if (data->cmds[index + 1])
		cmd->out_fd = data->pipe[1];
	dup_childs(data, cmd, index);
	if (exec_builtin(data, cmd))
		exit_free(data);
	if (access(cmd->args[0], X_OK) == -1)
		get_exec(data, cmd, data->path);
	if (cmd->is_valid)
		execve(cmd->args[0], cmd->args, data->env);
	exit_free(data);
}

static void	handle_parent(t_data *data, t_cmd *cmd, size_t  index)
{
	// printf("Parent process\n");
	//show_cmd(cmd);
	close(data->pipe[1]);
	if (data->cmds[index + 1] && data->cmds[index + 1]->in_fd == 0)
		data->cmds[index + 1]->in_fd = data->pipe[0];
	else
		close(data->pipe[0]);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
}

static void	ft_exec(t_data *data, t_cmd *cmd, size_t index)
{
	pid_t	pid;

	pipe(data->pipe);
	pid = fork();
	data->childs++;
		
	if (pid == 0)
		handle_child(data, cmd, index);
	else
		handle_parent(data, cmd, index);
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
