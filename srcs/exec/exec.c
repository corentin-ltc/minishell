/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:55:00 by cle-tort          #+#    #+#             */
/*   Updated: 2024/08/21 03:42:52 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_exec(t_data *data, char **name)
{
	size_t	i;
	char	*exec_backslash;
	char	*exec;

	i = 0;
	while (data->paths[i])
	{
		exec_backslash = ft_strjoin(data->paths[i], "/");
		if (!exec_backslash)
			exit_error ("An allocation failed\n", data);
		exec = ft_strjoin(exec_backslash, *name);
		free(exec_backslash);
		if (!exec)
			exit_error ("An allocation failed\n", data);
		if (access(exec, X_OK) != -1)
		{
			free(*name);
			*name = exec;
			return ;
		}
		free(exec);
		i++;
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(*name, 2);
}

char	**get_paths(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			return (ft_split(&envp[i][5], ":"));
		i++;
	}
	return (NULL);
}

static void	ft_child(t_cmd **cmds, t_data *data, size_t index, int fd[2])
{
	close(fd[0]);
	if (cmds[index]->out_fd != -42)
	{
		dup2(cmds[index]->out_fd, STDOUT_FILENO);
		close(cmds[index]->out_fd);
	}
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(cmds[index]->args[0], cmds[index]->args, data->env);
	// exit error execve
}

void	ft_exec(t_data *data, t_cmd **cmds, int index)
{
	char	**paths;
	int		pid;
	int		fd[2];

	if (pipe(fd) == -1)
		// exit and free
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		// exit error
	}
	if (pid == 0)//&& !check_builtin(cmds[index].args, &data->env))
	{
		if (access(cmds[index]->args[0], X_OK) == -1)
			get_exec(data, cmds[index]->args);
		ft_child(cmds, data, index, fd);
	}
	else
	{
		close(fd[1]);
		if (cmds[index + 1]->args && cmds[index + 1]->in_fd == -42)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		else
			dup2(cmds[index + 1]->in_fd, STDIN_FILENO);
		//close in_fd?
	}
}

void	maxi_piping(t_data *data, t_cmd **cmds)
{
	int	index;
	int	fd[2];
	int	pid;

	if (cmds[0]->in_fd != -42)
		dup2(cmds[0]->in_fd, STDIN_FILENO);
	index = 0;
	while (cmds[index + 1]->args)
	{
		ft_exec(data, cmds, index);
		ft_putarr(cmds[index]->args);
		index++;
	}
	if (cmds[index]->out_fd != STDOUT_FILENO)
	{
		perror("allo");
		dup2(cmds[index]->out_fd, STDOUT_FILENO);
	}
	pid = fork();
	if (pid == -1)
	{
		// exit error
	}
	if (pid == 0)
	{
		perror("allo");
		if (access(cmds[index]->args[0], X_OK) == -1)
			get_exec(data, cmds[index]->args);
		ft_putarr(cmds[index]->args);
		execve(cmds[index]->args[0], cmds[index]->args, data->env);
	}
	wait(NULL);
}

