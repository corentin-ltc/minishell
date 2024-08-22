/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/22 20:25:40 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_data *data, t_cmd *cmd)
{
	size_t	i;
	size_t	len;

	i = 1;
	while (cmd->args[i])
	{
		len = 0;
		while (cmd->args[i][len] && cmd->args[i][len] != '=')
			len++;
		cmd->args[i][len] = '\0';
		if (len != 0 || len != ft_strlen(cmd->args[i]))
		{
			if (!ft_setenv(cmd->args[i], &(cmd->args[i][len + 1]), &(data->env)))
				exit(EXIT_FAILURE);
		}
		i++;
	}
}
