/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:48:55 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_data *data, t_cmd *cmd)
{
	size_t	i_arg;
	size_t	i_env;

	i_arg = 1;
	while (cmd->args[i_arg])
	{
		i_env = 0;
		while (data->env[i_env])
		{
			if (!ft_strncmp(cmd->args[i_arg], data->env[i_env], ft_strlen(cmd->args[i_arg])))
			{
				if (!ft_remove_index(&(data->env), i_env))
					exit(EXIT_FAILURE);
				else
					break ;
			}
			i_env++;
		}
		i_arg++;
	}
}
