/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 15:48:07 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_flagchar(char *str, char flag)
{
	bool	is_flag;
	size_t	i;
	size_t	j;

	if (str[0] != '-')
		return (false);
	i = 1 + ft_skipcharset(&str[1], "n");
	if (str[i] == '\0')
		return (true);
	return (false);
}

void	ft_echo(char **argv, char **env)
{
	bool	n_flag;
	size_t	i;

	n_flag = is_flagchar(argv[1], 'n');
	i = 1;
	while (n_flag && is_flagchar(argv[i], 'n'))
		i++;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		i++;
		if (argv[i])
			ft_putstr(" ");
	}
	if (!n_flag)
		ft_putendl("");
}
