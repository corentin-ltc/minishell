/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 15:48:29 by nbellila         ###   ########.fr       */
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

void	ft_cd(char **argv, char ***env)
{
	char	*dir;
	char	*path;

	path = argv[1];
	if (path && argv[2])
		return (shell_error("cd", "too many arguments"));
	if (path == NULL || !ft_strcmp(path, "--"))
	{
		path = ft_getenv("HOME", *env);
		if (!path)
			return (shell_error("cd", "no HOME environment variable"));
	}
	if (!ft_strcmp(path, "-"))
	{
		path = ft_getenv("OLDPWD", *env);
		if (!path)
			return (shell_error("cd", "no OLDPWD environment variable"));
	}
	if (!check_access(path))
		return (perror(path));
	if (!ft_cd_update_env(path, env))
		exit(EXIT_FAILURE);
}
