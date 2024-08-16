/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/18 20:00:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av)
{
	int	not_heredoc;

	if (ac < 2)
		exit_error("Wrong number of arguments\n", NULL);
	not_heredoc = ft_strncmp(av[1], "here_doc", 8);
	if (ac < 5 || (!not_heredoc && ac < 6))
		exit_error("Wrong number of arguments\n", NULL);
	if (not_heredoc && access(av[1], F_OK))
		perror(av[1]);
	else if (not_heredoc && access(av[1], R_OK))
		perror(av[1]);
	if (!access(av[ac - 1], F_OK) && access(av[ac - 1], W_OK))
		perror(av[ac - 1]);
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

char	***get_args(t_data data, char **av)
{
	char	***args;
	size_t	i;

	args = malloc((data.count + 1) * sizeof(char **));
	if (!args)
		return (NULL);
	i = 0;
	while (i < data.count)
	{
		args[i] = ft_split(av[i + 2 + data.is_heredoc], " ");
		if (!args[i])
		{
			while (i--)
				free_2d((void **)args[i], 0);
			return (free(args), NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}

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

void	*check_exec(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->args[i])
	{
		if (access(data->args[i][0], X_OK) == -1)
			get_exec(data, &data->args[i][0]);
		i++;
	}
	return (data);
}
