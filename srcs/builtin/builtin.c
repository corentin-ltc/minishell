/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:23:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 17:42:01 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_builtin(char **argv, char ***env)
{
	if (!ft_strcmp(argv[0], "echo"))
		ft_echo(argv, *env);
	else if (!ft_strcmp(argv[0], "cd"))
		ft_cd(argv, *env);
	else if (!ft_strcmp(argv[0], "pwd"))
		ft_pwd(argv, *env);
	else if (!ft_strcmp(argv[0], "env"))
		ft_env(argv, *env);
	else if (!ft_strcmp(argv[0], "unset"))
		ft_unset(argv, env);
	else if (!ft_strcmp(argv[0], "export"))
		ft_export(argv, env);
	else if (!ft_strcmp(argv[0], "exit"))
		exit(EXIT_SUCCESS);
	else 
		return (false);
	return (true);
}