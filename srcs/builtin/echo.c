/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:59:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 01:54:54 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_n_flag(char *str)
{
	size_t	i;

	if (str[0] != '-')
		return (false);
	i = 1 + ft_skipcharset(&str[1], "n");
	if (str[i] == '\0')
		return (true);
	return (false);
}

void	ft_echo(t_data *data, t_cmd *cmd)
{
	bool	n_flag;
	size_t	i;

	data->exit_code = 0;
	if (cmd->args[1] == NULL)
		return ;
	n_flag = is_n_flag(cmd->args[1]);
	i = 1;
	while (n_flag && is_n_flag(cmd->args[i]))
		i++;
	while (cmd->args[i])
	{
		ft_putstr(cmd->args[i]);
		i++;
		if (cmd->args[i])
			ft_putstr(" ");
	}
	if (!n_flag)
		ft_putendl("");
}
