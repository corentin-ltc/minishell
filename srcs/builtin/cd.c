/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:21:12 by nbellila         ###   ########.fr       */
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

void	ft_cd(t_data *data, t_cmd *cmd)
{
	char	*dir;
	char	*path;

	path = cmd->args[1];
	if (path && cmd->args[2])
		return (shell_error("cd", "too many arguments"));
	if (path == NULL || !ft_strcmp(path, "--"))
	{
		path = ft_getenv("HOME", data->env);
		if (!path)
			return (shell_error("cd", "no HOME environment variable"));
	}
	if (!ft_strcmp(path, "-"))
	{
		path = ft_getenv("OLDPWD", data->env);
		if (!path)
			return (shell_error("cd", "no OLDPWD environment variable"));
	}
	if (!check_access(path))
		return (perror(path));
	if (!ft_cd_update_env(path, &(data->env)))
		exit(EXIT_FAILURE);
}
