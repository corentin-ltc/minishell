/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 19:18:29 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **argv, char **env)
{
	size_t	i;
	bool	newline;
	
	newline = true;
	i = 1;
	if (!ft_strcmp("-n", argv[i]))
	{
		newline = false;
		i = 2;
	}
	while (argv[i])
	{
		ft_putstr(argv[i]);
		i++;
		if (argv[i])
			ft_putstr(" ");
	}
	if (newline)
		ft_putstr("\n");
}