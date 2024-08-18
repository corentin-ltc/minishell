/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:03:46 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 15:50:21 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **argv, char ***env)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argv[1])
	{
		status = ft_atoi(argv[1]);
		if (status < 0 || status > 255)
			status = EXIT_SUCCESS;
	}
	ft_putstr("exit\n");
	exit(status);
}