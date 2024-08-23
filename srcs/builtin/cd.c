/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 07:08:39 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_access(char *path)
{
	void	*dir;

	dir = opendir(path);
	if (!dir)
		return (false);
	closedir(dir);
	return (true);
}

static void	*ft_cd_update_env(char *path, char ***env)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (NULL);
	chdir(path);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(oldpwd);
		return (NULL);
	}
	if (!ft_setenv("OLDPWD", oldpwd, env) || !ft_setenv("PWD", pwd, env))
	{
		free(oldpwd);
		free(pwd);
		return (NULL);
	}
	free(oldpwd);
	free(pwd);
	return (path);
}

static char	*get_path(t_data *data, char *str)
{
	char	*path;

	path = str;
	if (str == NULL || !ft_strcmp(str, "--") || !ft_strcmp(str, "~"))
	{
		path = ft_getenv("HOME", data->env);
		if (!path)
			shell_error("cd", "no HOME environment variable");
	}
	else if (!ft_strcmp(str, "-"))
	{
		path = ft_getenv("OLDPWD", data->env);
		if (!path)
			shell_error("cd", "no OLDPWD environment variable");
	}
	else if (!check_access(path))
	{
		perror(path);
		return (NULL);
	}
	return (path);
}

void	ft_cd(t_data *data, t_cmd *cmd)
{
	char	*path;

	if (cmd->args[1] && cmd->args[2])
	{
		data->exit_code = 1;
		shell_error("cd", "too many arguments");
		return ;
	}
	path = get_path(data, cmd->args[1]);
	if (!path)
	{
		data->exit_code = 1;
		return ;
	}
	if (!ft_cd_update_env(path, &(data->env)))
		exit_error("update pwd alloc failed", data);
}
