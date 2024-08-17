/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 18:41:13 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **argv, char **env)
{
	char	*path;

	path = argv[1];
	if (path && argv[2])
		return (shell_error("cd", "too many arguments"));
	if (path == NULL || !ft_strcmp(path, "--"))
	{
		path = ft_getenv("HOME", env);
		if (!path)
			return (shell_error("cd", "no HOME environment variable"));
	}
	if (!ft_strcmp(path, "-"))
	{
		path = ft_getenv("OLDPWD", env);
		if (!path)
			return (shell_error("cd", "no OLDPWD environment variable"));
	}
	//todo: update OLDPWD et PWD
	chdir(path);
}