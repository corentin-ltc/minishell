/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:23:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 18:52:02 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_builtin(char **argv)
{
	if (!ft_strcmp(argv[0], "echo"))
		ft_echo(argv);
	else if (!ft_strcmp(argv[0], "cd"))
		chdir(argv[1]);
	else if (!ft_strcmp(argv[0], "pwd"))
		ft_pwd(argv);
	else if (!ft_strcmp(argv[0], "exit"))
		exit(EXIT_SUCCESS);
	else 
		return (false);
	return (true);
}