/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 22:45:28 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_data *data, t_cmd *cmd)
{
	size_t	i;
	size_t	name;

	data->exit_code = 0;
	i = 1;
	while (cmd->args[i])
	{
		name = 0;
		while (cmd->args[i][name] && cmd->args[i][name] != '=')
			name++;
		if (name > 0 && cmd->args[i][name] == '=')
		{
			cmd->args[i][name] = '\0';
			if (!ft_setenv(cmd->args[i], &(cmd->args[i][name + 1]), &(data->env)))
				exit_error("setenv alloc failed", data);
		}
		else
			data->exit_code = 1;
		i++;
	}
}
