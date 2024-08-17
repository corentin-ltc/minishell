/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 18:30:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **argv, char **env)
{
	char	*path;

	path = argv[1];
	if (path && argv[2])
		return (shell_error("cd", "too many arguments"));
	if (path == NULL)
	{
		path = ft_getenv("HOME", env);
		if (!path)
			return (shell_error("cd", "no HOME environment variable"));
	}
	chdir(path);
}