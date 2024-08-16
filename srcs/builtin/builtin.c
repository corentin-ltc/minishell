/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:23:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 18:43:32 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_builtin(char **argv)
{
	if (!ft_strcmp(argv[0], "echo"))
		ft_echo(argv);
	else if (!ft_strcmp(argv[0], "cd"))
		ft_cd(argv);
	else if (!ft_strcmp(argv[0], "exit"))
		ft_exit(argv);
	else 
		return (false);
	return (true);
}