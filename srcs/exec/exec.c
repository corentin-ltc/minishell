/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:39:35 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 01:25:15 by nabil            ###   ########.fr       */
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
	if (access(cmd->args[0], X_OK) == -1)
		shell_error(cmd->args[0], "command not found");
	cmd->is_valid = false;
}

static void redirect_cmd(t_data *data, t_cmd *cmd, size_t index)
{
	//infile
	close(data->pipe[0]);
	if (index == 0 && cmd->in_fd == 0)
		cmd->in_fd = dup(STDIN_FILENO);
	dup2(cmd->in_fd, STDIN_FILENO);
	close(cmd->in_fd);
	//outfile
	if (data->cmds[index + 1] == NULL && cmd->out_fd == 0)
		cmd->out_fd = dup(STDOUT_FILENO);
	else if (data->cmds[index + 1] != NULL && cmd->out_fd == 0)
		cmd->out_fd = dup(data->pipe[1]);
	close(data->pipe[1]);
	dup2(cmd->out_fd, STDOUT_FILENO);
	close(cmd->out_fd);
}

static void	handle_child(t_data *data, t_cmd *cmd, size_t index)
{
	if (cmd->is_valid == false)
	{
		data->exit_code = 1;
		exit_free(data);
	}
	redirect_cmd(data, cmd, index);
	if (exec_builtin(data, cmd))
		exit_free(data);
	if (data->path)
		get_exec(data, cmd, data->path);
	else if (access(cmd->args[0], X_OK) == -1)
	{
		perror(cmd->args[0]);
		cmd->is_valid = false;
	}
	if (!cmd->is_valid)
		data->exit_code = 127;
	else
	{
		execve(cmd->args[0], cmd->args, data->env);
		data->exit_code = 1;
	}
	exit_free(data);
}

static void	handle_parent(t_data *data, t_cmd *cmd, size_t  index)
{
	close(data->pipe[1]);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
	if (data->cmds[index + 1] && data->cmds[index + 1]->in_fd == 0)
		data->cmds[index + 1]->in_fd = dup(data->pipe[0]);
	close(data->pipe[0]);
}

void	exec_cmds(t_data *data)
{
	pid_t	pid;
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		if (pipe(data->pipe) == -1)
			exit_error("A pipe failed", data);
		pid = fork();
		if (pid == -1)
			exit_error("A fork failed", data);
		data->childs++;
		if (pid == 0)
			handle_child(data, data->cmds[i], i);
		else
			handle_parent(data, data->cmds[i], i);
		i++;
	}
	wait_childs(data);
}
